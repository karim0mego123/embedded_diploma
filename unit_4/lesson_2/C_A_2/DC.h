/*
 * DC.h
 *
 *  Created on: Oct 17, 2022
 *      Author: karim
 */

#ifndef DC_H_
#define DC_H_

#include"states.h"

extern int speed;
void Set_Speed(int s);
STATE_define(DC_Idel);
STATE_define(DC_Busy);
#endif /* DC_H_ */

