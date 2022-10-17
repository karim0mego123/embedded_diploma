/*
 * C_A.c
 *
 *  Created on: Oct 17, 2022
 *      Author: karim
 */

#include "CA.h"
#include "states.h"
#include <stdio.h>
enum{
	waiting,
	driving
}state_id;

//variables definitions
unsigned int distance,speed=0,threshould=50;


//global pointer to function definition
void(*state)();

STATE_define(waiting)
{
	state_id=waiting;
	speed=0;
	printf("CA_Waiting state: distance=%d	speed=%d \n",distance,speed);
	Set_Speed(speed);
}
STATE_define(driving)
{
	state_id=driving;
	speed=30;
	printf("CA_Driving state: distance=%d	speed=%d \n",distance,speed);
	Set_Speed(speed);
}
int generate_random(int l,int r,int count)
{

	for (int i=0;i<count;i++)
	{
		int rand_num=(rand() %(r-l+1))+l;
		return rand_num;
	}
	return 0;
}

void set_distance(int d)
{
	distance=d;
	(d<=threshould) ? (state=STATE(waiting)) :(state=STATE(driving));
}

