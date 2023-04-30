/*
 * LM35_Sensor.h
 *
 * Created: 4/29/2023 2:57:28 AM
 *  Author: karim
 */ 


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "ErrorState.h"
#include "Types.h"
#include "DIO.h"
#include "ADC_INT.h"


ES_t LM35_Init(uint8_t Channel_id);
ES_t LM35_Read(uint16_t* value);


#endif /* LM35_SENSOR_H_ */