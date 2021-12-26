/*
 * traffic_light.c
 *
 *  Created on: Oct 19, 2021
 *      Author: ADMIN
 */

#include "main.h"
#include "led_display.h"
#include "input_processing.h"
#include "timer.h"
typedef enum {RED, GREEN, AMBER } eLightState;
int Time_in_state_1 = 0;
int Time_in_state_2 = 0;

void Traffic_Light_Update(void)
{
	switch(Light_state_G)
	{
	case RED:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
		++Time_in_state_1;
		display7SEG_1(Time_in_state_1/10);
		display7SEG_2(Time_in_state_1%10);
		if(Time_in_state_1 == red_duration)
		{
			Light_state_G = GREEN;
			Time_in_state_1 = 0;
		}
		break;
	case AMBER:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
		++Time_in_state_1;
		display7SEG_1(Time_in_state_1/10);
		display7SEG_2(Time_in_state_1%10);
		if(Time_in_state_1 == yellow_duration)
		{
			Light_state_G = RED;
			Time_in_state_1 = 0;
		}
		break;
	case GREEN:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
		++Time_in_state_1;
		display7SEG_1(Time_in_state_1/10);
		display7SEG_2(Time_in_state_1%10);
		if(Time_in_state_1 == green_duration)
		{
			Light_state_G = AMBER;
			Time_in_state_1 = 0;
		}
		break;
	}
}
void Traffic_Light_Updatenext(void)
{
	switch(Light_state_H)
	{
	case RED:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		++Time_in_state_2;
		display7SEG_3(Time_in_state_2/10);
		display7SEG_4(Time_in_state_2%10);
		if(Time_in_state_2 == red_duration)
		{
			Light_state_H = GREEN;
			Time_in_state_2 = 0;
		}
		break;
	case AMBER:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		++Time_in_state_2;
		display7SEG_3(Time_in_state_2/10);
		display7SEG_4(Time_in_state_2%10);
		if(Time_in_state_2 == yellow_duration)
		{
			Light_state_H = RED;
			Time_in_state_2 = 0;
		}
		break;
	case GREEN:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		++Time_in_state_2;
		display7SEG_3(Time_in_state_2/10);
		display7SEG_4(Time_in_state_2%10);
		if(Time_in_state_2 == green_duration)
		{
			Light_state_H = AMBER;
			Time_in_state_2 = 0;
		}
		break;
	}
}
void Traffic_Light_Init(void)
{
	Light_state_G = RED;
	Light_state_H = GREEN;
}
