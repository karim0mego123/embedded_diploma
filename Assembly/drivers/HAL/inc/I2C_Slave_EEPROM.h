/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Apr 20, 2023
 *      Author: karim
 */

#ifndef INC_I2C_SLAVE_EEPROM_H_
#define INC_I2C_SLAVE_EEPROM_H_

#include "I2C.h"

//E2PROM is an I2C Slave
//Idle Mode : device is in high - impedance state and wait for data
//Master Transmitter Mode : the device transmit data to slave receiver
//Master Receiver Mode : the device receives data from slave transmitter

#define EEPROM_Slave_address 0x2A

void eeprom_init(void);
unsigned char eeprom_write_Nbytes(unsigned int Memory_address , unsigned char* bytes , uint8_t Data_Length);
unsigned char eeprom_read_bytes(unsigned int Memory_address , uint8_t* dataOut , uint8_t Data_Length);


#endif /* INC_I2C_SLAVE_EEPROM_H_ */
