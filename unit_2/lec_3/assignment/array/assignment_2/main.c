/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: karim
 */
#include "stdio.h"
int main ()
{
	int j , y  ;
	float x[1000] , sum = 0  ;
	printf("enter number of students : ") ;
	fflush(stdin) ; 	fflush(stdout) ;
	scanf("%d",&y) ;
	fflush(stdin) ; 	fflush(stdout) ;
	for ( j = 0 ; j < y ; j++ )
	{
		scanf("%f",&x[j]) ;
		sum += x[j] ;
	}
	fflush(stdin) ; 	fflush(stdout) ;
	printf("%.2f",(float)sum/y) ;
	return 0 ;
}
