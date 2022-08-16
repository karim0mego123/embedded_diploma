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
	printf("enter the element to be inserted : " ) ;
	fflush (stdin) ; fflush(stdout) ;
	scanf("%d",&q) ;
	printf("enter the location : ") ;
	fflush (stdin) ; fflush(stdout) ;
	scanf("%d",&l) ;
	for ( i = x+1 ; i>=l ; i-- )
	{
		y[i] = y[i-1] ;
	}
	y[l-1] = q ;
	for( i = 0 ; i<x+1 ; i++ )
	{
		printf("%d	",y[i] ) ;
	}
	return 0 ;
}
