/*
 * I2C.h
 *
 * Created: 4/19/2023 2:43:20 PM
 *  Author: karim
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "Regesters.h"
#include "utils.h"
#include "Types.h"
#include "ErrorState.h"
#include "I2C_Priv.h"
#include "I2C_Config.h"

ES_t IIC_INIT() ;  

ES_t IIC_StartCondition() ; 

ES_t IIC_ReapeatedStartCondition();

ES_t IIC_StopCondition();

ES_t IIC_WriteSlaveAddress( uint8_t Copy_SlaveAddress , uint8_t Copy_Operation ) ; 

ES_t IIC_WriteData(uint8_t Copy_Data) ; 

ES_t IIC_CheckMyAddress() ;

ES_t II2_ReadData(uint8_t * Copy_Data) ; 


#endif /* I2C_H_ */