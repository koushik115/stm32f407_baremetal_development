/*
 * gpio.h
 *
 *  Created on: 08-May-2026
 *      Author: kaush
 */

#ifndef GPIO_H_
#define GPIO_H_

#define GPIODEN					(1U << 3U)
#define PIN_12_SET				(1U << 12U)
#define PIN_13_SET				(1U << 13U)
#define PIN_14_SET				(1U << 14U)
#define PIN_15_SET				(1U << 15U)
#define PIN_12_RESET			(1U << 28U)
#define PIN_13_RESET			(1U << 29U)
#define PIN_14_RESET			(1U << 30U)
#define PIN_15_RESET			(1U << 31U)
#define GREEN_LED_SET			PIN_12_SET
#define ORANGE_LED_SET 			PIN_13_SET
#define RED_LED_SET				PIN_14_SET
#define BLUE_LED_SET			PIN_15_SET
#define GREEN_LED_RESET			PIN_12_RESET
#define ORANGE_LED_RESET 		PIN_13_RESET
#define RED_LED_RESET			PIN_14_RESET
#define BLUE_LED_RESET			PIN_15_RESET

void led_init(void);

void green_led_on(void);
void orange_led_on(void);
void red_led_on(void);
void blue_led_on(void);

void green_led_off(void);
void orange_led_off(void);
void red_led_off(void);
void blue_led_off(void);

#endif /* GPIO_H_ */
