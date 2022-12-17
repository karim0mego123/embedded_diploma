/*
 * DIO.h
 *
 * Created: 12/13/2022 11:58:39 AM
 *  Author: karim
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "avr/io.h"
#include "util\delay.h"
#include "..\utilities\Types.h"
#include "..\utilities\utils.h"

// All Driver Macros
#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'

//** PORT states **//
#define LOW 0
#define HIGH 1


//** PORT directions **//
#define IN 0
#define OUT 1

// DIO_PrortoTypes
void DIO_Init( uint8_t PortNumber , uint8_t PinNumber , uint8_t Direction ) ;
void DIO_Write( uint8_t PortNumber , uint8_t PinNumber , uint8_t value  ) ;
void DIO_Read( uint8_t PortNumber , uint8_t PinNumber , uint8_t* value  );
void DIO_Toggle( uint8_t PortNumber , uint8_t PinNumber  );


#endif /* DIO_H_ */