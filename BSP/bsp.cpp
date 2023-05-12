/*
 * bsp.cpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */
#include "led.hpp"
#include "beep.hpp"
#include "bsp.hpp"
#include "key1.h"

/* bsp初始化 */
void bsp_init()
{
	led(1);
	beep(1);
	HAL_Delay(250);
	led(0);
	beep(0);

}
void set_time(uint8_t time){
	beep beep(time);
}

/* bsp循环主程序 */
void bsp_loop()
{
	key1 key;
	beep beep;
	led led;

	if(key.Key1_State(1))
	{
		beep.Beep_on_time(500);
	}
	beep.Beep_timeout_close_handle();
	led.Led_status_handle();
	HAL_Delay(10);
}
