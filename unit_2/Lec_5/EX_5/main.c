/*
 * main.c
 *
 *  Created on: Jul 28, 2022
 *      Author: karim
 */
#include "stdio.h"
# define pi		3.14
# define area 	(pi * r * r )
int main ()
{
	float r ;
	printf("enter radius of circle = " ) ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%f",&r) ;
	printf("%.2f",area) ;
	return 0 ;
}
