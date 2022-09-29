/*
 * lifo.h
 *
 *  Created on: Sep 18, 2022
 *      Author: karim
 */

#ifndef LIFO_H_
#define LIFO_H_
#define arra_size	3
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define Clean_buffer 	{	fflush(stdin) ; \
						fflush(stdout) ; }
typedef uint32_t	element_type ;
typedef struct student {
	element_type item ;
} Sstudent_t ;
typedef struct init {
	int* count ;
	Sstudent_t person[arra_size] ;
} Sperson_t;

typedef enum
{
	lifo_no_error ,
	lifo_full ,
	lifo_empty
} status_e ;
status_e push_student ( Sperson_t *lifo , int* count  ) ;
status_e pop_student ( Sperson_t *lifo , int* count  ) ;
status_e peek_student ( Sperson_t *lifo , int* count  ) ;
status_e print ( Sperson_t *lifo , int* count  ) ;

#endif /* LIFO_H_ */
