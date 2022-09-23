/*
 * main.c
 *
 *  Created on: Sep 18, 2022
 *      Author: karim
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdint.h>
#define pushStudent	1
#define popStudent		2
#define peekStudent	4
#define exit_programm	5
#define print_lifo	3
#define true	1
#include "lifo.h"
int main ()
{
	uint16_t number_Of_Student ;
	printf("enter number of students you want to enter = " )  ;
	fflush(stdout) ;
	scanf("%hu",&number_Of_Student) ;
	int n = -1 ;
	Sperson_t lifo  ;
	lifo.person = (Sstudent_t*)malloc ( sizeof(Sstudent_t)*number_Of_Student) ;
	lifo.count = &n ;
	uint32_t loc_choice ;
	while(true)
	{
		printf("1-push student\n" ) ;
		printf("2- pop student\n") ;
		printf("3-print your lifo\n") ;
		printf("4-peek last student\n") ;
		printf("5-exit\n") ;
		printf("enter your choice = " ) ;
		fflush(stdout) ;
		scanf("%d",&loc_choice) ;
		switch (loc_choice)
		{
		case pushStudent :
			if ( push_student( &lifo , lifo.count ) )
				printf("lifo is full\n") ;
			break ;
		case popStudent :
			if ( pop_student ( &lifo , lifo.count ) == lifo_empty )
				printf("lifo is empty\n") ;
			break ;
		case print_lifo :
			if ( print( &lifo , lifo.count ) == lifo_empty )
				printf("lifo is empty\n") ;
			break ;
		case peekStudent :
			if ( peek_student ( &lifo , lifo.count ) == lifo_empty )
				printf("lifo is empty\n") ;
			break ;
		case exit_programm :
			exit(1) ;
		default :
			printf("you have entered wrong choice " ) ;
			break ;
		}
	}
	return lifo_no_error ;
}


