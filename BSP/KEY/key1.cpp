/*
 * key1.cpp
 *
 *  Created on: 2023年5月10日
 *      Author: Shiwe
 */

#include <KEY/key1.h>

/* 检测按钮是否按下，如果按下，转换state */
key1::key1() {
	// TODO Auto-generated constructor stub

}
key1::~key1() {
	// TODO Auto-generated destructor stub
}

key1::key1(uint8_t state)
{
	Key_set_state(state);
}

/* 切换按钮状态 */
uint8_t key1::Key_toggle_state(uint8_t state)
{
	uint8_t s = key_count % 2;
	if(state == KEY_PRESSED)
	{
		s = 1;
	}
	else if(state == KEY_RELEASED)
	{
		s = 0;
	}
	else{

	}
	return s;
}

uint8_t key1::Key_is_pressed()
{
	if (!HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin))
		{
			return KEY_PRESSED; // 如果按键被按下，则返回KEY_PRESS
		}
		return KEY_RELEASED;   // 如果按键是松开状态，则返回KEY_RELEASE

}

uint8_t key1::Key1_State(uint8_t mode)
{
	static uint16_t key1_state = 0;

	if (Key_is_pressed() == KEY_PRESSED)
	{
		if (key1_state < (mode + 1) * 2)
		{
			key1_state++;
		}
	}
	else
	{
		key1_state = 0;
	}
	if (key1_state == 2)
	{
		key_count ++;
		return KEY_PRESSED;
	}
	return KEY_RELEASED;
}

/* 获取按钮状态 */
bool key1::Key_get_state()
{
	bool s;
	s = Key_toggle_state(GET_STATE);
	return s;
}
