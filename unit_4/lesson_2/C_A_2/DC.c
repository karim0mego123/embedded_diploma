/*
 * DC.c
 *
 *  Created on: Oct 17, 2022
 *      Author: karim
 */

#include "DC.h"
#include"states.h"
#include<stdio.h>
void(*DC_State)();
enum{
	DC_busy,
	DC_idel
}DC_state_id;
void Set_Speed(int s)
{
	speed=s;
	DC_state_id=DC_busy;
	DC_State=STATE(DC_Busy);
	printf("-------Dc_Speed= %d-------\n",speed);
}


STATE_define(DC_Idel)
{
	DC_state_id=DC_idel;
	printf("--------DC_Idel_State--------\n");

}
STATE_define(DC_Busy)
{
	DC_state_id=DC_busy;
	//
	printf("--------DC_Busy_State--------\n");
	printf("DC_Motor_Speed=%d\n",speed);
}
