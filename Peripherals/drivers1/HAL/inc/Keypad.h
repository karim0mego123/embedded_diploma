/*
 * Keypad.h
 *
 * Created: 1/29/2023 12:08:10 AM
 *  Author: karim
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f103xx.h"
#include "GPIO.h"

#define KeyPAd_PORT_Data	GPIOB


#define R0	GPIO_PIN_0
#define R1	GPIO_PIN_1
#define R2	GPIO_PIN_3
#define R3	GPIO_PIN_4
#define C0	GPIO_PIN_5
#define C1	GPIO_PIN_6
#define C2	GPIO_PIN_7
#define C3	GPIO_PIN_8

void KeYPad_Init();
char KeyPAd_Scan();





#endif /* KEYPAD_H_ */
