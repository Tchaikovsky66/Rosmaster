<<<<<<< HEAD
/*
 * led.cpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */


#include "led.hpp"

led::led(){


}

led::~led(){

}

led::led(uint8_t status)
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

/* 根据延时，循环十次转换led状态 */
void led::Led_status_handle()
{
	static uint16_t count;
	count++;
	if(count > 10)
	{
		count = 0;
		LED_TOGGLE();
	}
}


=======
/*
 * led.cpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */


#include "led.hpp"

led::led(){


}

led::~led(){

}

led::led(uint8_t status)
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
void led::Led_status_handle()
{
	static uint16_t count;
	count++;
	if(count > 10)
	{
		count = 0;
		LED_TOGGLE();
	}
}


>>>>>>> 6b96accd256eec03b2d69e808de3233ca6542d4b
