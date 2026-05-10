/*
 * timer.c
 *
 *  Created on: 10-May-2026
 *      Author: kaush
 */

#include "stm32f407xx.h"   // Device-specific register definitions for STM32F407
#include "timer.h"

/**
 * @brief Initialize and start TIM2 with given prescaler and auto-reload values
 *
 * @param preScalerValue   Prescaler value (divides timer input clock)
 * @param autoReloadValue  Auto-reload value (defines timer period)
 */
void tim2_enable(uint16_t preScalerValue, uint32_t autoReloadValue)
{
	// Enable clock for TIM2 peripheral (APB1 bus)
	RCC->APB1ENR |= TIM2CLCK_EN;

	// Set prescaler: actual division = (PSC + 1)
	// Reduces timer clock frequency
	TIM2->PSC = preScalerValue - 1;

	// Set auto-reload register: timer counts from 0 to ARR
	// Defines the period before update event occurs
	TIM2->ARR = autoReloadValue - 1;

	// Reset counter value to start from 0
	TIM2->CNT = 0;

	// Enable the timer (start counting)
	TIM2->CR1 |= TIM2CTRL_EN;
}

/**
 * @brief Check if update event (UEV) flag is set
 *
 * @return uint8_t  Non-zero if update event occurred, else 0
 */
uint8_t tim2_uev(void)
{
	// Read status register and check update event flag (UIF bit)
	return (TIM2->SR & TIM2UEV_FLAG);
}

/**
 * @brief Clear the update event flag (UIF)
 */
void tim2_clear_uev_flag(void)
{
	// Clear UIF flag by writing 0 to the bit
	TIM2->SR &= ~TIM2UEV_FLAG;
}
