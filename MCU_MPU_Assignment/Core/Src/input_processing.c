/*
 * input_processing.c
 *
 *  Created on: Dec 4, 2023
 *      Author: ASUS
 */


#include "main.h"
#include "global.h"
#include "input_processing.h"
#include "input_reading.h"
#include "timer.h"
#include "uart.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};

enum ButtonState button_0_state = BUTTON_PRESSED;
enum ButtonState button_1_state = BUTTON_PRESSED;
enum ButtonState button_2_state = BUTTON_PRESSED;
enum ButtonState button_3_state = BUTTON_PRESSED;

void fsm_button_processing() {

	switch (button_0_state) {
			case BUTTON_RELEASED:
				if (is_button_pressed(0)) {
					button_0_state = BUTTON_PRESSED;
					if(curr_ped_status==PED_OFF&&(status==MODE1||status==RED_GREEN||status==RED_AMBER||status==GREEN_RED||status==AMBER_RED)){
						curr_ped_status=PED_ON;

					}
				}
				break;
			case BUTTON_PRESSED:
				if (!is_button_pressed(0)) {
					button_0_state = BUTTON_RELEASED;
				} else {
					if (is_button_pressed_1s(0)) {
						button_0_state = BUTTON_PRESSED_MORE_THAN_1_SECOND;
					}
				}
				break;
			case BUTTON_PRESSED_MORE_THAN_1_SECOND:
				if (!is_button_pressed(0)) {
					button_0_state = BUTTON_RELEASED;
				}
				// do nothing, wait for the button to be released./
				break;
		}
	switch (button_1_state) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1)) {
				button_1_state = BUTTON_PRESSED;
				if (status == RED_GREEN || status == RED_AMBER || status == GREEN_RED || status == AMBER_RED){
					status = MODE2;
				}
				if (status == AUTO_RED) 	status = MODE3;
				if (status == AUTO_AMBER) 	status = MODE4;
				if (status == AUTO_GREEN) 	status = MODE1;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1)) {
				button_1_state = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(1)) {
					button_1_state = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1)) {
				button_1_state = BUTTON_RELEASED;
			}
			// do nothing, wait for the button to be released
			break;
	}

	switch (button_2_state) {
		case BUTTON_RELEASED:
			if (is_button_pressed(2)) {
				button_2_state = BUTTON_PRESSED;
				if (status == AUTO_RED || status == ADJ_RED) {
					status = ADJ_RED;
					T_RED++;
					if (T_RED >= 99) T_RED = 1;
					disp_t_red_uart();
				}
				if (status == AUTO_AMBER || status == ADJ_AMBER) {
					status = ADJ_AMBER;
					T_AMBER++;
					if (T_AMBER >= 5) T_AMBER = 1;
					disp_t_amber_uart();
				}
				if (status == AUTO_GREEN || status == ADJ_GREEN) {
					status = ADJ_GREEN;
					T_GREEN++;
					if (T_GREEN >= 99) T_GREEN = 1;
					disp_t_green_uart();
				}
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(2)) {
				button_2_state = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(2)) {
					button_2_state = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(2)) {
				button_2_state = BUTTON_RELEASED;
			}
			// do nothing, wait for the button to be released.
			break;
	}

	switch (button_3_state) {
		case BUTTON_RELEASED:
			if (is_button_pressed(3)) {
				button_3_state = BUTTON_PRESSED;
				if (status == ADJ_RED) {

					if (T_RED <= T_AMBER) T_RED = T_AMBER + 1;
					T_GREEN = T_RED - T_AMBER;

					status = MODE1;
				}
				if (status == ADJ_AMBER) {

					if (T_RED <= T_AMBER) T_RED = T_AMBER + 1;
					T_GREEN = T_RED - T_AMBER;
					status = MODE1;
				}
				if (status == ADJ_GREEN) {

					if (T_AMBER + T_GREEN >= 99) {
						T_AMBER = 4;
						T_GREEN = 95;
					}
					T_RED = T_AMBER + T_GREEN;
					status = MODE1;
				}
				//display save msg and change to mode 1 with the updated time
				HAL_UART_Transmit(&huart2, "!SAVED#\n\r", 11, 50);
				HAL_UART_Transmit(&huart2, "\n\r", 4, 50);
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(3)) {
				button_3_state = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(3)) {
					button_3_state = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(3)) {
				button_3_state = BUTTON_RELEASED;
			}
			// do nothing, wait for the button to be released
			break;
	}
}
