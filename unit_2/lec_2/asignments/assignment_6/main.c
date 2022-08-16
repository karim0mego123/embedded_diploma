/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */

#include "stdio.h"
int main ()
{

	int x , y , temp ;
	printf("enter value of x = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	printf("enter value of y = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%d",&y) ;
	temp = x ;
	x = y ;
	y = temp ;
	printf("x = %d\n",x) ;
	printf("y = %d\n",y) ;
	return 0 ;
}
