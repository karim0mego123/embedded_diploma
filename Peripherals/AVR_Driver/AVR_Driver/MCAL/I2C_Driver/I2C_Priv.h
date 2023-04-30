/*
 * I2C_Priv.h
 *
 * Created: 4/19/2023 2:47:34 PM
 *  Author: karim
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#include "Types.h"

#define IIC_MASTER		3
#define IIC_SLAVE		2

#define TWDR	*((uint8_t*)0x23)
#define TWAR	*((uint8_t*)0x22)
#define TWSR	*((uint8_t*)0x21)
#define TWBR	*((uint8_t*)0x20)
#define TWDR	*((uint8_t*)0x56)

#define  BITRATE(IIC_SPEED) ((F_CPU-16UL*IIC_SPEED)/(2UL*IIC_SPEED*IIC_PRES))


#endif /* I2C_PRIV_H_ */