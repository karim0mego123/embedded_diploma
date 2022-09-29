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
	printf("enter any element : " ) ;
	fflush(stdout) ;
	scanf("%d",&lifo->person[*count].item) ;
	return lifo_no_error ;
}
status_e pop_student ( Sperson_t* lifo , int* count  )
{
	if ( *count == -1 )
		return lifo_empty ;
	printf("%d\n",lifo->person[*count].item) ;
	--*count ;
	return lifo_no_error ;
}
status_e peek_student ( Sperson_t* lifo , int* count  )
{
	if ( *count == -1 )
		return lifo_empty ;
	printf("%d\n",lifo->person[*count].item ) ;
	return lifo_no_error ;
}
status_e print ( Sperson_t* lifo , int* count  )
{
	if ( *count == -1 )
		return lifo_empty ;
	for ( int i = 0 ; i <= *count ; i++ )
	{
		printf("%d\n",(lifo->person+i)->item ) ;

	}
	return lifo_no_error ;
}
