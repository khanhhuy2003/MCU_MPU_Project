/*
 * input_processing.c
 *
 *  Created on: Dec 7, 2023
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

}
