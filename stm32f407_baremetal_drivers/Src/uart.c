/*
 * uart.c
 *
 *  Created on: 13-May-2026
 *      Author: kaush
 */

#include "uart.h"
#include "stm32f407xx.h"   // Device register definitions for STM32F407

// Internal helper to configure baud rate register
static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate);

// Computes BRR value based on peripheral clock and desired baudrate
static uint32_t compute_buadrate(uint32_t periph_clk, uint32_t baudrate);

// Low-level function to transmit a single character
static void uart_write(int ch);

/**
 * @brief Retargets printf to UART
 *
 * This function is called internally by printf.
 * It sends one character at a time via UART.
 */
int __io_putchar(int ch)
{
	uart_write(ch);  // Send character over UART
	return ch;
}

/**
 * @brief Initialize UART2 (TX only)
 *
 * Configures:
 * - GPIOA pin PA2 as alternate function (USART2_TX)
 * - Baud rate
 * - Enables UART transmitter
 */
void uart_init(void)
{
	// Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	// Set PA2 mode to Alternate Function (10)
	GPIOA->MODER &= ~(1U << 4U);  // Clear bit 4
	GPIOA->MODER |= (1U << 5U);   // Set bit 5 → AF mode

	// Configure PA2 alternate function to AF7 (USART2_TX)
	// AFR[0] corresponds to pins 0–7
	GPIOA->AFR[0] |= (1U << 8U);   // AF bit 0
	GPIOA->AFR[0] |= (1U << 9U);   // AF bit 1
	GPIOA->AFR[0] |= (1U << 10U);  // AF bit 2
	GPIOA->AFR[0] &= ~(1U << 11U); // AF bit 3 → 0 → AF7

	// Enable clock access to USART2 (APB1 bus)
	RCC->APB1ENR |= UART2EN;

	// Configure baud rate
	uart_set_baudrate(APB1_CLCK, DEBUG_UART_BAUDRATE);

	// Enable USART module
	USART2->CR1 |= CR1_UE;

	// Enable transmitter
	USART2->CR1 |= CR1_TE;
}

/**
 * @brief Set baud rate register (BRR)
 */
static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate)
{
	// Write computed baud rate value into BRR register
	USART2->BRR = compute_buadrate(periph_clk, baudrate);
}

/**
 * @brief Compute USART BRR value
 *
 * Uses integer approximation:
 * BRR = peripheral_clock / baudrate
 *
 * Adding (baudrate / 2) improves rounding accuracy
 */
static uint32_t compute_buadrate(uint32_t periph_clk, uint32_t baudrate)
{
	return ((periph_clk + (baudrate / 2)) / baudrate);
}

/**
 * @brief Transmit a single character via UART
 *
 * @param ch Character to transmit
 */
static void uart_write(int ch)
{
	// Wait until transmit data register is empty (TXE flag set)
	while(!(USART2->SR & SR_TXE));

	// Write data to data register (only lower 8 bits used)
	USART2->DR = (ch & 0xFF);
}
