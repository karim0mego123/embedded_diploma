/*
 * CA.h
 *
 *  Created on: Oct 17, 2022
 *      Author: karim
 */


#ifndef CA_H_
#define CA_H_
#include "states.h"
int generate_random(int l,int r,int count);
STATE_define(waiting);
STATE_define(driving);
void set_distance(int d);
extern void Set_Speed(int s);


extern void (*state)();
#endif /* CA_H_ */


