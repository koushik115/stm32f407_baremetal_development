/*
 * systick.c
 *
 *  Created on: 09-May-2026
 *      Author: kaush
 */

#include "systick.h"
#include "stm32f407xx.h"   // Provides SysTick register structure

/**
 * @brief Blocking delay using SysTick timer (polling COUNTFLAG)
 */
void systick_ms_delay(uint32_t ms_delay)
{
	// Load value for 1 ms delay
	// LOAD is a 24-bit register → max value = 0xFFFFFF
	SysTick->LOAD = ONE_MSEC_LOAD - 1U;

	// Clear current value register
	// Writing any value clears VAL and COUNTFLAG
	SysTick->VAL = 0U;

	// Select clock source (Processor clock = AHB)
	SysTick->CTRL |= CTRL_CLCKSRC;

	// Enable SysTick timer
	SysTick->CTRL |= CTRL_EN;

	// Loop for required milliseconds
	for(uint32_t i = 0; i < ms_delay; i++)
	{
		// Wait until COUNTFLAG is set
		// COUNTFLAG = 1 when timer counts down to 0
		while(!(SysTick->CTRL & CTRL_COUNTFLAG));
	}

	// Disable SysTick timer
	SysTick->CTRL = 0U;
}
