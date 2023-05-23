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
#include "bsp_uart.h"
#include "cmsis_os.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "dma.h"
#include "stdio.h"

uint8_t task_beep_flag = 0; //按鍵控制beep狀態

/* bsp初始化 */
void bsp_init()
{
	led(1);
	beep(1);
	HAL_Delay(250);
	led(0);
	beep(0);
	//USART1_Init();

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
		BEEP_ON();
		osDelay(100);
		BEEP_OFF();
		osDelay(100);
	}
}

/* Key控制 */
void Task_Entity_KEY()
{
	key1 key;
	uint8_t TXbuff[16] = "send: hello\n";
	static uint16_t count = 0;
	while(1)
	{
		if(key.Key1_State(1) == KEY_PRESSED)
		{
			task_beep_flag = 1;
			USART1_Send_ArrayU8(TXbuff,sizeof(TXbuff));
			USART1_Send_ArrayU8(TXbuff,5);
			count++;
			printf("press:%d\n",count); //printf重定向
		}
		// The buzzer automatically shuts down when times out   蜂鸣器超时自动关闭
		//task_beep_flag = 0;
	}
	osDelay(10);

}

void Task_Entity_Usart_RX()
{
		uint8_t ch = 0;
		HAL_UART_Receive_IT(&huart1, (uint8_t *)&ch, 1);
//	static uint8_t ch =0;
//	//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
//	HAL_UART_Receive(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
//	//HAL_UART_Transmit_IT(&huart1, (uint8_t *)&ch, 1);
//		if(ch == '0')
//		{
//			LED_OFF();
//		}
//		else if(ch == '1')
//		{
//			LED_ON();
//		}
//		osDelay(10);
}
