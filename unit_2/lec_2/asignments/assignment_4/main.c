/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	float x , y ;
	printf("enter first number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&x) ;
	printf("enter second number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&y) ;
	printf("sum = %.2f",(float)x*y) ;
	return 0 ;
}
