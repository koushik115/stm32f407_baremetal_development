/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>   // Fixed-width integer types
#include "gpio.h"     // Custom GPIO driver (LED + button control)

// Warn if FPU is enabled in compiler but not initialized in runtime
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU."
#endif

int main(void)
{
	// Initialize peripherals
	led_init();     // Configure PD12–PD15 as output
	button_init();  // Configure PA0 as input

    /* Infinite loop (bare-metal super loop) */
	for(;;)
	{
		// Read button state (PA0)
		uint8_t buttonValue = read_button_input();

		if(buttonValue)
		{
			// Button pressed → Turn ON LEDs sequentially

			green_led_on();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++); // crude blocking delay

			orange_led_on();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++);

			red_led_on();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++);

			blue_led_on();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++);
		}
		else
		{
			// Button not pressed → Turn OFF LEDs sequentially

			green_led_off();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++);

			orange_led_off();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++);

			red_led_off();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++);

			blue_led_off();
			for(volatile uint32_t delay = 0; delay < 1000000; delay++);
		}
	}
}
