/*
 * US.c
 *
 *  Created on: Oct 17, 2022
 *      Author: karim
 */

#include"US.h"
#include "stdio.h"
enum{
	US_busy,
	US_idel
}US_State_Id;
void(*US_State)();
STATE_define(US_busy)
{
	US_State_Id=US_busy;
	//ultrasonic get distance
	unsigned int d=generate_random(45,55,1);
	set_distance(d);
	US_State=STATE(US_busy);
    printf("US_busy_state : distance : %d \n",d);
}


