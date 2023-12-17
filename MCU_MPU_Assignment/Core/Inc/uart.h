/*
 * uart.h
 *
 *  Created on: Dec 7, 2023
 *      Author: ASUS
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#define MODE1 		0
#define RED_GREEN 	1
#define RED_AMBER 	2
#define GREEN_RED 	3
#define AMBER_RED 	4

void fsm_uart();
void disp_t_red_uart();
void disp_t_amber_uart();
void disp_t_green_uart();
void disp_time_uart(int t_road_1, int t_road_2);

#endif /* INC_UART_H_ */
