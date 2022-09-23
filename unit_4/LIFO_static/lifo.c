/*
 * lifo.c
 *
 *  Created on: Sep 18, 2022
 *      Author: karim
 */
#include "Stdio.h"
#include "lifo.h"
#include "string.h"
#include <stdint.h>
#define arra_size	3

status_e push_student ( Sperson_t* lifo , int* count  )
{
	if ( *count == arra_size-1	)
	{
		return lifo_full ;
	}
	++*count ;
	printf("enter your name : " ) ;
	fflush(stdout) ;
	scanf("%s",(lifo->person+*count)->name) ;
	printf("enter your age : " ) ;
	fflush(stdout) ;
	scanf("%d",&((lifo->person+*count)->age)) ;
	printf("enter your id : " ) ;
	fflush(stdout) ;
	scanf("%d",&((lifo->person+*count)->id)) ;
	return lifo_no_error ;
}
status_e pop_student ( Sperson_t* lifo , int* count  )
{
	if ( *count == -1 )
		return lifo_empty ;
	printf("name of student is : %s\n",lifo->person[*count] . name ) ;
	printf("age  of student is : %d\n",(lifo->person+*count)->age)  ;
	printf("id   of student is : %d\n",(lifo->person+*count)->id) ;
	--*count ;
	return lifo_no_error ;
}
status_e peek_student ( Sperson_t* lifo , int* count  )
{
	if ( *count == -1 )
		return lifo_empty ;
	printf("name of student is : %s\n",lifo->person[*count] . name ) ;
	printf("age  of student is : %d\n",(lifo->person+*count)->age)  ;
	printf("id   of student is : %d\n",(lifo->person+*count)->id) ;
	return lifo_no_error ;
}
status_e print ( Sperson_t* lifo , int* count  )
{
	if ( *count == -1 )
		return lifo_empty ;
	for ( int i = 0 ; i <= *count ; i++ )
	{
		printf("name of student is : %s\n",(lifo->person+i)->name ) ;
		printf("age  of student is : %d\n",(lifo->person+i)->age  )   ;
		printf("id   of student is : %d\n",(lifo->person+i)->id   ) ;
	}
	return lifo_no_error ;
}



