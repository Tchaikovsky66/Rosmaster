/*
 * led.hpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */
#include "main.h"

#ifndef LED_LED_HPP_
#define LED_LED_HPP_

#define LED_ON()         HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET)
#define LED_OFF()        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET)
#define LED_TOGGLE()     HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin)



void led(uint8_t status);
void Led_status_handle();



#endif /* LED_LED_HPP_ */
