/*
 * bsp.hpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */

#ifndef __BSP_H__
#define __BSP_H__

//#ifndef SRC_BSP_HPP_
//#define SRC_BSP_HPP_

#include <beep.h>
#include <led.h>
#include "stdio.h"
#include "stdint.h"

/* Import HAL related library  导入HAL相关库 */
#include "main.h"
#include "gpio.h"
#include "usart.h"

#include "stm32f1xx_hal.h"
#include "stm32f103xe.h"

#include "tim.h"
/* Import device driver library  导入设备驱动库 */
#include "mpuiic.h"
#include "mpu9250.h"
#include "key1.h"
#include "bsp_uart.h"
#include "motor.h"
#include "encoder.h"
#include "motor_pid.h"
#include "motion.h"

#include "stdio.h"


void bsp_loop();
void bsp_init();
void Bsp_Led_Show_State_Handle(void);
void Task_Entity_LED();
void Task_Entity_BEEP();
void Task_Entity_KEY();
void Task_Entity_Usart_RX();
void Task_Entity_MPU();
void Motor_Test(void);

#endif /* SRC_BSP_HPP_ */
