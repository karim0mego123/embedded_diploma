/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	int x , y  ;
	printf("enter value of x = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	printf("enter value of y = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&y) ;
	x+=y ;
	y = x - y ;
	x = x - y ;
	printf("x = %d\n",x) ;
	printf("y = %d\n",y) ;
	return 0 ;
}
