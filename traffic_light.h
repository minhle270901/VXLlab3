/*
 * traffic_light.h
 *
 *  Created on: Oct 19, 2021
 *      Author: ADMIN
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_
typedef enum {RED, GREEN, AMBER } eLightState;
extern int Time_in_state_1;
extern int Time_in_state_2;

void Traffic_Light_Init(void);
void Traffic_Light_Update(void);
void Traffic_Light_Updatenext(void);

#endif /* INC_TRAFFIC_LIGHT_H_ */
