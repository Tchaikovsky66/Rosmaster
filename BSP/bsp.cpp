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
#include "cmsis_os.h"

uint8_t task_beep_flag = 0; //按鍵控制beep狀態

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

void bsp_loop()
{
	key1 key;
	beep beep;
	led led;



	if(key.Key1_State(1)){
		beep.Beep_on_time(500);
//		if(key.Key_toggle_state(GET_STATE)){
//			LED_TOGGLE();
//		}
	}
	beep.Beep_timeout_close_handle();
	led.Led_status_handle();
	HAL_Delay(10);
}


//Freertos

/* led控制 */
void Task_Entity_LED()
{
	while(1)
	{
		LED_TOGGLE();
		osDelay(100);
	}
}

/* Beep控制 */
void Task_Entity_BEEP()
{
	while(1)
	{
		if(task_beep_flag == 1)
		{
			BEEP_ON();
			osDelay(200);
			BEEP_OFF();
			osDelay(200);
		}
		else
		{
			BEEP_OFF();
		}
	}
}

/* Key控制 */
void Task_Entity_KEY()
{
	key1 key;
	while(1)
	{
		if(key.Key1_State(1) == KEY_PRESSED)
			task_beep_flag = !task_beep_flag;
	}
	osDelay(10);
}
