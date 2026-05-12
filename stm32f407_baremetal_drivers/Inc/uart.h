/*
 * uart.h
 *
 *  Created on: 13-May-2026
 *      Author: kaush
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

// Enable clock for GPIOA (bit 0 in RCC AHB1ENR register)
#define GPIOAEN				(1U << 0U)

// Enable clock for USART2 (bit 17 in RCC APB1ENR register)
#define UART2EN				(1U << 17U)

// Default baud rate for debugging (used in UART initialization)
#define	DEBUG_UART_BAUDRATE	115200UL

// System clock frequency
#define SYS_FREQ			16000000UL

// APB1 peripheral clock (USART2 is connected to APB1 bus)
#define APB1_CLCK			SYS_FREQ

// USART Control Register 1 (CR1) bits

// Transmitter enable bit (TE) -> enables UART transmission
#define CR1_TE				(1U << 3U)

// USART enable bit (UE) -> enables the USART peripheral
#define CR1_UE				(1U << 13U)

// USART Status Register (SR) bits

// Transmit data register empty (TXE)
// Set when data register is ready to accept new data
#define SR_TXE				(1U << 7U)

// Initialize UART2 peripheral
void uart_init(void);

#endif /* UART_H_ */
