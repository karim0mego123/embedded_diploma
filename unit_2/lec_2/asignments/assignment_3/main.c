/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	int x , y ;
	printf("enter first number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	printf("enter second number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&y) ;
	printf("sum = %d",x+y) ;
	return 0 ;
}
