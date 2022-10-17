/*
 * US.h
 *
 *  Created on: Oct 17, 2022
 *      Author: karim
 */


#ifndef US_H_
#define US_H_
#include "states.h"

extern void set_distance(int d);
STATE_define(US_busy);
int generate_random(int l,int r,int count);

#endif /* US_H_ */

