/*
 * global.h
 *
 *  Created on: Dec 7, 2023
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 		-1
#define MODE1 		0
#define RED_GREEN 	1
#define RED_AMBER 	2
#define GREEN_RED 	3
#define AMBER_RED 	4

#define MODE2 		5
#define AUTO_RED 	6
#define ADJ_RED		7

#define MODE3 		8
#define AUTO_AMBER	9
#define ADJ_AMBER	10

#define MODE4 		11
#define AUTO_GREEN	12
#define ADJ_GREEN	13

extern UART_HandleTypeDef huart2;

enum PEDESTRIAN_STATE{PED_ON,PED_OFF};

extern int T_RED;
extern int T_AMBER;
extern int T_GREEN;
extern int T_CHECK;
extern int status;
extern enum PEDESTRIAN_STATE curr_ped_status;
extern int volume;
extern int buzzer_period;

void led_config();
void toggle_red();
void toggle_amber();
void toggle_green();

#endif /* INC_GLOBAL_H_ */
