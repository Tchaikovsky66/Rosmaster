/*
 * bsp_uart.h
 *
 *  Created on: May 16, 2023
 *      Author: Shiwe
 */

#ifndef UART_BSP_UART_H_
#define UART_BSP_UART_H_

#include "main.h"

void USART1_Init(void);
void USART1_Send_U8(uint8_t ch);
void USART1_Send_ArrayU8(uint8_t *BufferPtr, uint16_t Length);


#endif /* UART_BSP_UART_H_ */
