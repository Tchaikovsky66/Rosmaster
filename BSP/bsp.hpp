/*
 * bsp.hpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */

#ifndef SRC_BSP_HPP_
#define SRC_BSP_HPP_


#ifdef __cpluscplus
extetrn "c"{
#endif
	void set_time(uint8_t );
	void bsp_loop();
	void bsp_init();
	void Task_Entity_LED(void);
	void Task_Entity_BEEP(void);
	void Task_Entity_KEY(void);
	void Task_Entity_Usart_RX();
#ifdef __cpluscplus
};
#endif


#endif /* SRC_BSP_HPP_ */
