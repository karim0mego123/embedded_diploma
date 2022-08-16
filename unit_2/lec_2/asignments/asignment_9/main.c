/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: karim
 */
#include "stdio.h"

int main ()
{
	char x ;
	printf("enter any alphabet = ") ;
	fflush(stdin) ; fflush(stdout) ;
	scanf("%c",&x) ;
	switch (x)
	{
	case 'a' :
	case 'A' :
	case 'e' :
	case 'E' :
	case 'o' :
	case 'O' :
	case 'i' :
	case 'I' :
	case 'u' :
	case 'U' :
		printf("alphabet is vowel") ;
		break ;
	default :
		printf("alphabet is consonants") ;
		break ;
	}
	return 0 ;
}

