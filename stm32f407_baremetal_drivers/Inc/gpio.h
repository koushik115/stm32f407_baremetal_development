/*
 * gpio.h
 *
 *  Created on: 08-May-2026
 *      Author: kaush
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>   // Standard integer types

/* ===================== CLOCK ENABLE MACROS ===================== */

// Enable clock for GPIOD (AHB1ENR bit 3)
#define GPIODEN					(1U << 3U)

// Enable clock for GPIOA (AHB1ENR bit 0)
#define GPIOAEN					(1U << 0U)


/* ===================== BUTTON CONFIGURATION ===================== */

// User button connected to PA0
// Used to mask bit 0 from IDR register
#define USER_BUTTON_PIN			(1U << 0U)


/* ===================== LED PIN DEFINITIONS ===================== */

// BSRR Register usage:
// Lower 16 bits  → SET pin HIGH
// Upper 16 bits  → RESET pin LOW

// SET operations (turn ON LEDs)
#define PIN_12_SET				(1U << 12U)   // PD12
#define PIN_13_SET				(1U << 13U)   // PD13
#define PIN_14_SET				(1U << 14U)   // PD14
#define PIN_15_SET				(1U << 15U)   // PD15

// RESET operations (turn OFF LEDs)
// Note: Reset bits are offset by +16 from pin number
#define PIN_12_RESET			(1U << 28U)   // (12 + 16)
#define PIN_13_RESET			(1U << 29U)   // (13 + 16)
#define PIN_14_RESET			(1U << 30U)   // (14 + 16)
#define PIN_15_RESET			(1U << 31U)   // (15 + 16)


/* ===================== LED ALIASES ===================== */

// Mapping LEDs to specific pins (STM32F407 Discovery board)
#define GREEN_LED_SET			PIN_12_SET
#define ORANGE_LED_SET 			PIN_13_SET
#define RED_LED_SET				PIN_14_SET
#define BLUE_LED_SET			PIN_15_SET

#define GREEN_LED_RESET			PIN_12_RESET
#define ORANGE_LED_RESET 		PIN_13_RESET
#define RED_LED_RESET			PIN_14_RESET
#define BLUE_LED_RESET			PIN_15_RESET


/* ===================== FUNCTION PROTOTYPES ===================== */

/**
 * @brief Initialize LED GPIO pins (PD12–PD15 as output)
 */
void led_init(void);

/**
 * @brief Initialize user button (PA0 as input)
 */
void button_init(void);

/**
 * @brief Read user button state
 * @return 1 → pressed, 0 → not pressed
 */
uint8_t read_button_input(void);


/* ===================== LED CONTROL FUNCTIONS ===================== */

/**
 * @brief Turn ON Green LED (PD12)
 */
void green_led_on(void);

/**
 * @brief Turn ON Orange LED (PD13)
 */
void orange_led_on(void);

/**
 * @brief Turn ON Red LED (PD14)
 */
void red_led_on(void);

/**
 * @brief Turn ON Blue LED (PD15)
 */
void blue_led_on(void);

/**
 * @brief Turn OFF Green LED (PD12)
 */
void green_led_off(void);

/**
 * @brief Turn OFF Orange LED (PD13)
 */
void orange_led_off(void);

/**
 * @brief Turn OFF Red LED (PD14)
 */
void red_led_off(void);

/**
 * @brief Turn OFF Blue LED (PD15)
 */
void blue_led_off(void);

#endif /* GPIO_H_ */
