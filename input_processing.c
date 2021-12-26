/*
 * input_processing.c
 *
 *  Created on: Oct 19, 2021
 *      Author: ADMIN
 */


#include "main.h"
#include "traffic_light.h"
#include "timer.h"
#include "input_reading.h"
#include "led_display.h"
int red_duration =5;
int green_duration = 3;
int yellow_duration = 2;
int Light_state_G;
int Light_state_H;
int flag_but1 = 0;
int flag_but2 = 0;
int flag_but3 = 0;
int state = 0;
int value = 0;

void fsm_for_input_processing ( void )
{
	switch(state)
	{
	case 0:
		if(timer0_flag == 1)
		{
			Traffic_Light_Update();
			Traffic_Light_Updatenext();
			setTimer0(1000);
		}
		if(is_button_pressed(0) && flag_but1 == 0)
		{
			flag_but1 = 1;
		}
		if(!is_button_pressed(0) && flag_but1 == 1)
		{
			state++;
			flag_but1 = 0;
		}
		break;
	case 1:
		if(timer0_flag == 1){
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0 );
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3 );
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
			setTimer0(500);
		}
		if(is_button_pressed(1) && flag_but2 == 0)
		{
			flag_but2 = 1;
		}
		if(!is_button_pressed(1) && flag_but2 == 1)
		{
			value++;
			flag_but2 = 0;
		}
		if(is_button_pressed(2) && flag_but3 == 0)
		{
			flag_but3 = 1;
		}
		if(!is_button_pressed(2) && flag_but3 == 1)
		{
			red_duration = value;
			value = 0;
			flag_but3 = 0;
		}
		if(is_button_pressed(0) && flag_but1 == 0)
		{
			flag_but1 = 1;
		}
		if(!is_button_pressed(0) && flag_but1 == 1)
		{
			state++;
			flag_but1 = 0;
		}
		display7SEG_1(value/10);
		display7SEG_2(value%10);
		display7SEG_3(0);
		display7SEG_4(state+1);
		break;
	case 2:
		if(timer0_flag == 1){
					HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1 );
					HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4 );
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
					setTimer0(500);
				}
				if(is_button_pressed(1) && flag_but2 == 0)
				{
					flag_but2 = 1;
				}
				if(!is_button_pressed(1) && flag_but2 == 1)
				{
					value++;
					flag_but2 = 0;
				}
				if(is_button_pressed(2) && flag_but3 == 0)
				{
					flag_but3 = 1;
				}
				if(!is_button_pressed(2) && flag_but3 == 1)
				{
					yellow_duration = value;
					value = 0;
					flag_but3 = 0;
				}
				if(is_button_pressed(0) && flag_but1 == 0)
				{
					flag_but1 = 1;
				}
				if(!is_button_pressed(0) && flag_but1 == 1)
				{
					state++;
					flag_but1 = 0;
				}
				display7SEG_1(value/10);
				display7SEG_2(value%10);
				display7SEG_3(0);
				display7SEG_4(state+1);
				break;
	case 3:
		if(timer0_flag == 1){
					HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2 );
					HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5 );
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
					setTimer0(500);
				}
				if(is_button_pressed(1) && flag_but2 == 0)
				{
					flag_but2 = 1;
				}
				if(!is_button_pressed(1) && flag_but2 == 1)
				{
					value++;
					flag_but2 = 0;
				}
				if(is_button_pressed(2) && flag_but3 == 0)
				{
					flag_but3 = 1;
				}
				if(!is_button_pressed(2) && flag_but3 == 1)
				{
					green_duration = value;
					value = 0;
					flag_but3 = 0;
				}
				if(is_button_pressed(0) && flag_but1 == 0)
				{
					flag_but1 = 1;
				}
				if(!is_button_pressed(0) && flag_but1 == 1)
				{
					state = 0;
					Time_in_state_1 = 0;
					Time_in_state_2 = 0;
					flag_but1 = 0;
				}
				display7SEG_1(value/10);
				display7SEG_2(value%10);
				display7SEG_3(0);
				display7SEG_4(state+1);
				break;
	}
}
