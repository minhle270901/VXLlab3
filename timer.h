/*
 * timer.h
 *
 *  Created on: Oct 19, 2021
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer0_flag;
void setTimer0 ( int duration );
void timer_run (void );
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim );

#endif /* INC_TIMER_H_ */
