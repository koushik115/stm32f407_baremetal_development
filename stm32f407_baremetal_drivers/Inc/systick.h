/*
 * systick.h
 *
 *  Created on: 09-May-2026
 *      Author: kaush
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

/* ===================== SYSTICK CTRL REGISTER BITS ===================== */

// Enable SysTick counter (bit 0)
#define CTRL_EN				(1U << 0U)

// Clock source selection (bit 2)
// 1 -> Processor clock (AHB)
// 0 -> External clock (AHB/8)
#define CTRL_CLCKSRC		(1U << 2U)

// COUNTFLAG (bit 16)
// Set to 1 when timer reaches 0 (overflow event)
#define CTRL_COUNTFLAG		(1U << 16U)


/* ===================== LOAD VALUE ===================== */

// For 16 MHz system clock:
// 1 ms = 16000 cycles
#define ONE_MSEC_LOAD		16000U


/* ===================== FUNCTION PROTOTYPE ===================== */

/**
 * @brief Generate blocking delay in milliseconds using SysTick
 * @param ms_delay Number of milliseconds
 */
void systick_ms_delay(uint32_t ms_delay);

#endif /* SYSTICK_H_ */
