/*
 * timer.c
 *
 *  Created on: Oct 19, 2021
 *      Author: ADMIN
 */

#include "main.h"
#include "input_reading.h"
int timer0_flag = 0;
int timer0_counter = 0;
int TIMER_CYCLE = 10;
void setTimer0 ( int duration ){
	timer0_counter = duration / TIMER_CYCLE ;
	timer0_flag = 0;
}
void timer_run (void)
{
	if( timer0_counter > 0)
	{
		timer0_counter --;
		if( timer0_counter == 0) timer0_flag = 1;
	}
}

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if(htim -> Instance == TIM2 )
	{
		button_reading ();
	}
	timer_run ();
}
