/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	float x , y , z , max ;
	printf("enter three numbers x , y , z = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f %f %f",&x,&y,&z) ;
	max = (x>y)? ( (x>z) ? x : z ) : ( (y>z) ? y : z ) ;
	printf("max value = %f",max) ;
	return 0 ;
}


