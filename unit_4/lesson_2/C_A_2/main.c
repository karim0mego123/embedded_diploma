/*
 * main.c
 *
 *  Created on: Oct 17, 2022
 *      Author: karim
 */
#include"stdio.h"
#include "CA.h"
#include "US.h"
#include "DC.h"
extern void(*state)();
extern void(*US_State)();
extern void(*DC_State)();
void main_init();
int main()
{
	main_init();
	while(1)
	{
		US_State();
		state();
		DC_State();
		//for(int i=0;i<50000;i++);
	}
	return 0 ;
}
void main_init()
{
	state=STATE(waiting);
	US_State=STATE(US_busy);
	DC_State=STATE(DC_Idel);
}

