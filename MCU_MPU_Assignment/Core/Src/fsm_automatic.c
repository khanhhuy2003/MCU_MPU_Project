/*
 * fsm_automatic.c
 *
 *  Created on: Dec 7, 2023
 *      Author: ASUS
 */


#include "main.h"
#include "global.h"
#include "fsm_automatic.h"
#include "timer.h"
#include "input_reading.h"
#include "uart.h"

int t_road_1 = 0, t_road_2 = 0;

void fsm_automatic() {
	switch (status) {
		case INIT:
			status = MODE1;
			break;
		case MODE1:
			led_config();
			t_road_1 = T_RED;
			t_road_2 = T_GREEN;
			HAL_UART_Transmit(&huart2, "!_____MODE1_____#\n\r", 20, 50);
			disp_time_uart(t_road_1, t_road_2);
			setTimer4(1000);
			buzzer_period=500;
			volume = 20;
			status = RED_GREEN;
			break;
		case RED_GREEN:
			led_config();
			if (timer4_flag == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_2 <= 0) { // next state pre-setup
					t_road_2 = T_AMBER;
					buzzer_period = 75;
					volume = 100;
					status = RED_AMBER; // Change state
				}
				disp_time_uart(t_road_1, t_road_2);
				setTimer4(1000);
			}
			break;
		case RED_AMBER:
			led_config();
			if (timer4_flag == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_1 <= 0) { // next state pre-setup
					t_road_1 = T_GREEN;
					t_road_2 = T_RED;
					status = GREEN_RED; // Change state
				}
				disp_time_uart(t_road_1, t_road_2);
				setTimer4(1000);
			}
			break;
		case GREEN_RED:
			led_config();
			if (timer4_flag == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_1 <= 0) { // next state pre-setup
					t_road_1 = T_AMBER;
					status = AMBER_RED; // Change state
				}
				disp_time_uart(t_road_1, t_road_2);
				setTimer4(1000);
			}
			break;
		case AMBER_RED:
			led_config();
			if (timer4_flag == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_1 <= 0) { // next state pre-setup
					t_road_1 = T_RED;
					t_road_2 = T_GREEN;
					buzzer_period=500;
					volume = 20;
					status = RED_GREEN; // Change state
				}
				disp_time_uart(t_road_1, t_road_2);
				setTimer4(1000);
			}
			break;
		default:
			break;
	}
}
