/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: karim
 */
#include "stdio.h"
int main ()
{
	int i , j ;
	float x[3][3] ;
	printf("enter  array : ") ;
	fflush(stdin) ; 	fflush(stdout) ;
	for ( i = 0 ; i < 3 ; i++ )
	{
		for ( j = 0 ; j < 3 ; j++ )
		{
			scanf("%f",&x[i][j]) ;
		}
	}
	printf("arrray after transpose : \n") ;
	fflush(stdin) ; 	fflush(stdout) ;
	for ( i = 0 ; i < 3 ; i++ )
	{
		for ( j = 0 ; j < 3 ; j++ )
		{
			printf("%.2f	",x[j][i]) ;
		}
		printf("\n") ;
	}
	return 0 ;
}
