/*
 * main.c
 *
 *  Created on: Aug 4, 2022
 *      Author: karim
 */
#include "stdio.h"
int main ()
{
	char x  ;
	char *p = &x ;
	for ( int i = 0 ; i < 26 ; i++ )
	{
		x = 65 ;
		*p = x + i ;
		printf("%c  ",*p) ;
	}
	return 0 ;
}

