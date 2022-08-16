/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	float x , y , min = 0 ;
	printf("enter two numbers = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f %f",&x,&y) ;
	min = (x<y)? x : y ;
	printf("min = %.3f",min) ;
	return 0 ;
}

