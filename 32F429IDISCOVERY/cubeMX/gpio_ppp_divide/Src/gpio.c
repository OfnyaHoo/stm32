/*
 * gpio.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: yeong
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
	HAL_Delay(1000);
	off_green_led();
	HAL_Delay(1000);
}
