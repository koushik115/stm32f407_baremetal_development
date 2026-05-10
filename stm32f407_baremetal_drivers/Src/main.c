/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>   // Fixed-width integer types
#include "gpio.h"     // Custom GPIO driver (LED + button control)
#include "systick.h"  // SysTick-based delay (currently not used)
#include "timer.h"    // TIM2 driver

// Delay for LED (used previously with SysTick)
#define LED_DELAY	500U

// Warn if FPU is enabled in compiler but not initialized in runtime
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU."
#endif

int main(void)
{
	// Initialize peripherals

	// Configure onboard LEDs (e.g., PD12–PD15 as output)
	led_init();

	// Configure user button (e.g., PA0 as input)
	button_init();

	// Initialize TIM2:
	// Prescaler = 16000 → reduces clock frequency
	// ARR = 1000 → defines period
	// Combined → generates periodic update event (used as delay)
	tim2_enable(16000U, 1000U);

    /* Infinite loop (bare-metal super loop) */
	for(;;)
	{
		// Read button state (PA0)
		uint8_t buttonValue = read_button_input();

		if(buttonValue)
		{
			// Button pressed → Turn ON LEDs sequentially

			green_led_on();

			// Wait until timer update event occurs (polling)
			while(!tim2_uev());

			// Clear update event flag for next cycle
			tim2_clear_uev_flag();

			orange_led_on();

			// Wait for next timer event
			while(!tim2_uev());
			tim2_clear_uev_flag();

			red_led_on();

			// Wait for next timer event
			while(!tim2_uev());
			tim2_clear_uev_flag();

			blue_led_on();

			// Wait for next timer event
			while(!tim2_uev());
			tim2_clear_uev_flag();
		}
		else
		{
			// Button not pressed → Turn OFF LEDs sequentially

			green_led_off();

			// Wait for timer event
			while(!tim2_uev());
			tim2_clear_uev_flag();

			orange_led_off();

			// Wait for timer event
			while(!tim2_uev());
			tim2_clear_uev_flag();

			red_led_off();

			// Wait for timer event
			while(!tim2_uev());
			tim2_clear_uev_flag();

			blue_led_off();

			// Wait for timer event
			while(!tim2_uev());
			tim2_clear_uev_flag();
		}
	}
}
