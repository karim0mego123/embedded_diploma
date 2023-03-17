/*
 * LED.h
 *
 * Created: 3/5/2023 11:23:03 PM
 *  Author: karim
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"

typedef struct {
	uint8_t PORT_ID ; 
	uint8_t PIN_ID ; 
	uint8_t Connection ; // sink or source  
}LED_t ;

#define Source_Current		0
#define Sink_Current		1

#define OFF					0
#define ON					1

void LED_Init_State(LED_t* LED , uint8_t LED_State);
void LED_ON(LED_t* LED ) ;
void LED_OFF(LED_t* LED ) ;

#endif /* LED_H_ */