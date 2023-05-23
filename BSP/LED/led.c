/*
 * led.cpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */


#include "led.h"

void led(uint8_t status)
{
	if(status == 0)
	{
		LED_OFF();
	}
	if(status == 1)
	{
		LED_ON();
	}
}
void Led_status_handle()
{
	static uint16_t count;
	count++;
	if(count > 10)
	{
		count = 0;
		LED_TOGGLE();
	}
}


