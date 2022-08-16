/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	int x ;
	printf("enter any number = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	if (x%2==0)
		printf("number is even") ;
	else
		printf("number is odd") ;
	return 0 ;
}
