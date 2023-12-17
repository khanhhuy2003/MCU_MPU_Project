/*
 * uart.c
 *
 *  Created on: Dec 7, 2023
 *      Author: ASUS
 */

#include "main.h"
#include "uart.h"
#include "global.h"
#include "timer.h"
#include "string.h"
#include "stdio.h"
#include "input_reading.h"
#include "input_processing.h"

void disp_t_red_uart() {
	HAL_UART_Transmit(&huart2, "!T_RED = ", 11, 50);
	char buffer[16];
	HAL_UART_Transmit(&huart2, (uint8_t*)buffer, sprintf(buffer, "%d\n\r", T_RED), 50);
}

void disp_t_amber_uart() {
	HAL_UART_Transmit(&huart2, "!T_AMBER = ", 11, 50);
	char buffer[16];
		HAL_UART_Transmit(&huart2, (uint8_t*)buffer, sprintf(buffer, "%d\n\r", T_AMBER), 50);
}

void disp_t_green_uart() {
	HAL_UART_Transmit(&huart2, "!T_GREEN = ", 11, 50);
	char buffer[16];
		HAL_UART_Transmit(&huart2, (uint8_t*)buffer, sprintf(buffer, "%d\n\r", T_GREEN), 50);
}

void disp_time_uart(int t_road_1, int t_road_2) {
	char buffer[16];
	HAL_UART_Transmit(&huart2, "!T_ROAD_1= ", 12, 50);
	HAL_UART_Transmit(&huart2, (uint8_t*)buffer, sprintf(buffer, "%d\n\r", t_road_1), 50);
	HAL_UART_Transmit(&huart2, "!T_ROAD_2= ", 12, 50);
	HAL_UART_Transmit(&huart2, (uint8_t*)buffer, sprintf(buffer, "%d\n\r", t_road_2), 50);
	HAL_UART_Transmit(&huart2, "\n", 2, 50);
}
