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
