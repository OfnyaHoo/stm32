/*
 * gpio.c
 *
 *  Created on: 2019. 7. 2.
 *      Author: user
 */

#include "gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

void on_green_led(void)
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
}

void off_green_led(void)
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
}

void blink_green_led(void)
{
	on_green_led();
	HAL_Delay(500);
	off_green_led();
	HAL_Delay(500);
}

void on_red_led(void)
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
}

void off_red_led(void)
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
}

void blink_red_led(void)
{
	on_red_led();
	HAL_Delay(500);
	off_red_led();
	HAL_Delay(500);
}
