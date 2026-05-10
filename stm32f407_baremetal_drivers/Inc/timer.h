/*
 * timer.h
 *
 *  Created on: 10-May-2026
 *      Author: kaush
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

// Enable clock for TIM2 (bit 0 in RCC APB1ENR register)
#define TIM2CLCK_EN		(1U << 0U)

// Enable counter (CEN bit in TIM2_CR1 register)
#define TIM2CTRL_EN		(1U << 0U)

// Update interrupt flag (UIF bit in TIM2_SR register)
// Set when timer overflows (CNT reaches ARR)
#define TIM2UEV_FLAG	(1U << 0U)

// Function to initialize and start TIM2
void tim2_enable(uint16_t preScalerValue, uint32_t autoReloadValue);

// Function to check update event flag
uint8_t tim2_uev(void);

// Function to clear update event flag
void tim2_clear_uev_flag(void);

#endif /* TIMER_H_ */
