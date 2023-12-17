/*
 * input_reading.h
 *
 *  Created on: Dec 7, 2023
 *      Author: ASUS
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

extern int button_flag[];
void button_reading();
int is_button_pressed(int index);
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
