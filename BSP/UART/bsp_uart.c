/*
 * bsp_uart.cpp
 *
 *  Created on: May 16, 2023
 *      Author: Shiwe
 */


#include "bsp_uart.h"

#include "../LED/led.h"
#include "main.h"
#include "usart.h"
uint8_t RxTemp = 0;

void USART1_Init(void)
{
    HAL_UART_Receive_IT(&huart1, (uint8_t *)&RxTemp, 1);
}

// The serial port sends one byte  串口发送一个字节
void USART1_Send_U8(uint8_t ch)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
}

// The serial port sends a string of data  串口发送一串数据
void USART1_Send_ArrayU8(uint8_t *BufferPtr, uint16_t Length)
{
    #if ENABLE_UART_DMA
    HAL_UART_Transmit_DMA(&huart1, BufferPtr, Length);
    #else
    while (Length--)
    {
        USART1_Send_U8(*BufferPtr);
        BufferPtr++;
    }
    #endif
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	static uint8_t ch =0;
	//HAL_UART_Transmit_IT(&huart1, (uint8_t *)&ch, 1);
		if(ch == '0')
		{
			LED_OFF();
		}
		else if(ch == '1')
		{
			LED_ON();
		}
		HAL_UART_Receive_IT(&huart1, (uint8_t *)&ch, 1);
}

//#ifdef __GNUC__
//#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
//#else
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
//#endif /* __GNUC__ */
//PUTCHAR_PROTOTYPE
//{
//    /* Place your implementation of fputc here */
//    /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
//    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
//    return ch;
//}
