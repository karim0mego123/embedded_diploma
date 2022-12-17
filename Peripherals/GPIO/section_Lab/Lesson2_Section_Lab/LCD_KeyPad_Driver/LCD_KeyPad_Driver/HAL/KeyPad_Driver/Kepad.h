/*
 * Kepad.h
 *
 * Created: 12/15/2022 12:20:18 PM
 *  Author: karim
 */ 


#ifndef KEPAD_H_
#define KEPAD_H_

 #include "avr/io.h"
#include "utils.h"
#include "Types.h"


#define	KeyPad_PORT	PORTD
#define KeyPad_PORT_DIR	DDRD
#define KeyPadPIN	PIND

#define R0	0
#define R1	1
#define R2	2
#define R3	3
#define C0	4
#define C1	5
#define C2	6
#define C3	7
void Key_Init();
char KeyPad_Scan();

#endif /* KEPAD_H_ */