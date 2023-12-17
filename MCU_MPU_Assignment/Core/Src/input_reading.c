/*
 * input_reading.c
 *
 *  Created on: Dec 4, 2023
 *      Author: ASUS
 */

#include "main.h"

#define N0_OF_BUTTONS 				       4



#define DURATION_FOR_AUTO_INCREASING	   100     // 1sec
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
#define BUTTON_1 GPIO

// the buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

// two buffers for debouncing - store to compare
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

// flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];

// counter for automatically increasing the value
// after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

static GPIO_TypeDef* button_ports[N0_OF_BUTTONS] = {A0_PedButton_GPIO_Port, A1_Button1_GPIO_Port, A2_Button2_GPIO_Port, A3_Button3_GPIO_Port};
static uint16_t button_pins[N0_OF_BUTTONS] = {A0_PedButton_Pin, A1_Button1_Pin, A2_Button2_Pin, A3_Button3_Pin};

void button_reading(void) {
	for (int i = 0; i < N0_OF_BUTTONS; i++) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(button_ports[i], button_pins[i]);

		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];

		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
			//if a button is pressed, we start counting
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForButtonPress1s[i]++;
			} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
				flagForButtonPress1s[i] = 1;
			}
		} else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

unsigned char is_button_pressed(uint8_t index){
	if (index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index){
	if (index >= N0_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}
