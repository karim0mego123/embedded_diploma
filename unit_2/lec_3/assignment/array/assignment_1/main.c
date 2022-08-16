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
	float x[2][2] , y[2][2] , sum[2][2] = {0} ;
	printf("enter first array : ") ;
	fflush(stdin) ; 	fflush(stdout) ;
	for ( i = 0 ; i < 2 ; i++ )
	{
		for ( j = 0 ; j < 2 ; j++ )
		{
			scanf("%f",&x[i][j]) ;
		}
		printf("\n") ;
	}
	printf("enter secind array : ") ;
	fflush(stdin) ; 	fflush(stdout) ;
	for ( i = 0 ; i < 2 ; i++ )
	{
		for ( j = 0 ; j < 2 ; j++ )
		{
			scanf("%f",&y[i][j]) ;
		}
		printf("\n") ;
	}
	printf("sum of two arrays = :\n") ;
	fflush(stdin) ; 	fflush(stdout) ;
	for ( i = 0 ; i < 2 ; i++ )
	{
		for ( j = 0 ; j < 2 ; j++ )
		{
			sum[i][j] = x[i][j]+y[i][j] ;
			printf("%.1f	",sum[i][j]) ;
		}
		printf("\n") ;
	}
	return 0 ;
}
