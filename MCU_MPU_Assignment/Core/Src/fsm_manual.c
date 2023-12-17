
#include "main.h"
#include "global.h"
#include "fsm_manual.h"
#include "timer.h"
#include "uart.h"

void fsm_red_manual() {
	switch(status) {
		case MODE2:
			led_config();
			setTimer1(500);
			HAL_UART_Transmit(&huart2, "!_____MODE2_____#\n\r", 20, 50);
			disp_t_red_uart();
			status = AUTO_RED;
			break;
		case AUTO_RED:
			if (timer1_flag == 1) {
				toggle_red();
				setTimer1(500);
			}
			break;
		case ADJ_RED:
			if (timer1_flag == 1) {
				toggle_red();
				setTimer1(500);
			}
			break;
		default:
			break;
	}
}

void fsm_amber_manual() {
	switch(status) {
		case MODE3:
			led_config();
			setTimer1(500);
			HAL_UART_Transmit(&huart2, "!_____MODE3_____#\n\r", 20, 50);
			disp_t_amber_uart();
			status = AUTO_AMBER;
			break;
		case AUTO_AMBER:
			if (timer1_flag == 1) {
				toggle_amber();
				setTimer1(500);
			}
			break;
		case ADJ_AMBER:
			if (timer1_flag == 1) {
				toggle_amber();
				setTimer1(500);
			}
			break;
		default:
			break;
	}
}

void fsm_green_manual() {
	switch(status) {
		case MODE4:
			led_config();
			setTimer1(500);
			HAL_UART_Transmit(&huart2, "!_____MODE4_____#\n\r", 20, 50);
			disp_t_green_uart();
			status = AUTO_GREEN;
			break;
		case AUTO_GREEN:
			if (timer1_flag == 1) {
				toggle_green();
				setTimer1(500);
			}
			break;
		case ADJ_GREEN:
			if (timer1_flag == 1) {
				toggle_green();
				setTimer1(500);
			}
			break;
		default:
			break;
	}
}
