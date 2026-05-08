/*
 * gpio.c
 *
 *  Created on: 07-May-2026
 *      Author: Koushik
 */

#include "gpio.h"
#include "stm32f407xx.h"   // Device header providing register definitions

/**
 * @brief Initialize LEDs connected to GPIOD (PD12–PD15)
 */
void led_init(void)
{
	// 1. Enable clock for GPIOD peripheral
	// AHB1ENR: AHB1 Peripheral Clock Enable Register
	// Setting bit corresponding to GPIOD enables its clock
	RCC->AHB1ENR |= GPIODEN;

	// 2. Configure PD12, PD13, PD14, PD15 as OUTPUT mode
	// Each GPIO pin has 2 bits in MODER register:
	/* -------- PD12 -------- */
	// Clear bit 25 (upper bit of MODER12)
	GPIOD->MODER &= ~(1U << 25U);
	// Set bit 24 → 01 (Output mode)
	GPIOD->MODER |= (1U << 24U);

	/* -------- PD13 -------- */
	GPIOD->MODER &= ~(1U << 27U);
	GPIOD->MODER |= (1U << 26U);

	/* -------- PD14 -------- */
	GPIOD->MODER &= ~(1U << 29U);
	GPIOD->MODER |= (1U << 28U);

	/* -------- PD15 -------- */
	GPIOD->MODER &= ~(1U << 31U);
	GPIOD->MODER |= (1U << 30U);

}

/**
 * @brief Initialize user button (PA0)
 */
void button_init(void)
{
	// Enable clock for GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	// Configure PA0 as INPUT mode
	GPIOA->MODER &= ~(1U << 0U);   // Clear bit 0
	GPIOA->MODER &= ~(1U << 1U);   // Clear bit 1

	// NOTE:
	// On STM32F407 Discovery board:
	// - USER button is connected to PA0
}
/**
 * @brief Turn ON Green LED (PD12)
 */
void green_led_on(void)
{
	// BSRR (Bit Set Reset Register):
	// Writing 1 to lower 16 bits → SET pin (HIGH)
	// This is atomic (no read-modify-write issues)
	GPIOD->BSRR |= GREEN_LED_SET;
}

/**
 * @brief Turn ON Orange LED (PD13)
 */
void orange_led_on(void)
{
	GPIOD->BSRR |= ORANGE_LED_SET;
}

/**
 * @brief Turn ON Red LED (PD14)
 */
void red_led_on(void)
{
	GPIOD->BSRR |= RED_LED_SET;
}

/**
 * @brief Turn ON Blue LED (PD15)
 */
void blue_led_on(void)
{
	GPIOD->BSRR |= BLUE_LED_SET;
}


/**
 * @brief Turn OFF Green LED (PD12)
 */
void green_led_off(void)
{
	// Writing to upper 16 bits of BSRR resets the pin (LOW)
	GPIOD->BSRR |= GREEN_LED_RESET;
}

/**
 * @brief Turn OFF Orange LED (PD13)
 */
void orange_led_off(void)
{
	GPIOD->BSRR |= ORANGE_LED_RESET;
}

/**
 * @brief Turn OFF Red LED (PD14)
 */
void red_led_off(void)
{
	GPIOD->BSRR |= RED_LED_RESET;
}

/**
 * @brief Turn OFF Blue LED (PD15)
 */
void blue_led_off(void)
{
	GPIOD->BSRR |= BLUE_LED_RESET;
}

/**
 * @brief Read user button state
 * @return 1 if pressed, 0 if not pressed
 */
uint8_t read_button_input(void)
{
	// Read Input Data Register (IDR)
	// Each bit corresponds to one GPIO pin state
	uint32_t GPIOA_PORT_VALUE = GPIOA->IDR;

	// Mask only PA0 bit and return its state
	return (GPIOA_PORT_VALUE & USER_BUTTON_PIN) ? 1U : 0U;
}
