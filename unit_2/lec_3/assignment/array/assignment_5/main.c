/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: karim
 */
#include "stdio.h"
int main ()
{
	int i = 0 ;
	int x  , y[10000] , l , q ;
	printf("enter number of elements : ") ;
	fflush (stdin) ; fflush(stdout) ;
	scanf("%d",&x) ;
	for( i = 0 ; i<x ; i++ )
	{
		scanf("%d",&y[i]) ;
	}
	fflush (stdin) ; fflush(stdout) ;
	printf("enter the element to be search : " ) ;
	fflush (stdin) ; fflush(stdout) ;
	scanf("%d",&q) ;
	for ( i = 0 ; i< x ; i++ )
	{
		if ( y[i] == q )
		{
			printf("number found at the location = %d",i+1) ;
			return 0 ;
		}
	}
	printf("number not found") ;
	return 0 ;
}
