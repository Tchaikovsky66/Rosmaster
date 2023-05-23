/*
 * bsp.cpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */
#include "bsp.h"

#include "key1.h"
#include "bsp_uart.h"
#include "cmsis_os.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "dma.h"
#include "stdio.h"

#include "beep/beep.h"
#include "LED/led.h"
#include "mpu9250.h"

uint8_t task_beep_flag = 0; //按鍵控制beep狀態

/* bsp初始化 */
void bsp_init()
{
	LED_ON();
	BEEP_ON();
	HAL_Delay(250);
	LED_OFF();
	BEEP_OFF();
	USART1_Init();

	if(MPU9250_Init() != 0)
	{
		printf("MPU9250 INIT ERROR\n");
		while(1);
	}


}

void bsp_loop()
{

	if(Key1_State(1))
	{
		Beep_On_Time(500);

	}
	Beep_Timeout_Close_Handle();
	Led_status_handle();
	HAL_Delay(10);
}

void Bsp_Led_Show_State_Handle(void)
{
	static uint8_t led_count = 0;
	led_count++;
	if (led_count > 20)
	{
		led_count = 0;
		LED_TOGGLE();
	}
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
	uint8_t TXbuff[16] = "send: hello\n";
	static uint16_t count = 0;
	while(1)
	{
		if(Key1_State(1) == KEY_PRESS)
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

void Task_Entity_MPU()
{

	MPU9250_Read_Data_Handle();

	Bsp_Led_Show_State_Handle();
	// The buzzer automatically shuts down when times out   蜂鸣器超时自动关闭
	Beep_Timeout_Close_Handle();
	osDelay(10);
}
