/*
 * fifo.c
 *
 *  Created on: Sep 22, 2022
 *      Author: karim
 */
#include "fifo.h"
#include "stdlib.h"
fifo_status_t fifo_init ( fifo_buf_t* fifo  )
{
	fifo->base = fifo->item ;
	fifo->head = fifo->item ;
	fifo->tail = fifo->item ;
	fifo->count = 0 ;
	return fifo_no_error ;
}
fifo_status_t fifo_enqueue ( fifo_buf_t* fifo )
{
	element_type buf ;
	if ( fifo->count == array_size )
	{
		return fifo_full ;
	}
	printf("enter element to enqueue = " ) ;
	fflush (stdin) ; fflush(stdout) ;
	scanf("%d",&buf) ;
	*(fifo->head) = buf ;
	fifo->count++ ;
	if ( fifo->head == &fifo->item[array_size-1] )
	{
		fifo->head = fifo->base ;
	}
	else
		fifo->head++ ;
	return fifo_no_error ;
}
fifo_status_t fifo_dequeue ( fifo_buf_t* fifo )
{
	if ( fifo->count == 0 )
		return fifo_empty ;
	printf("%d\n",*fifo->tail) ;
	fifo->count-- ;
	if ( fifo->tail == &fifo->item[array_size-1] )
	{
		fifo->tail = fifo->base ;
	}
	else
		fifo->tail++ ;
	return fifo_no_error ;
}
void fifo_print ( fifo_buf_t* fifo  )
{
	if ( fifo->count == 0 )
		printf("fifo is empty\n") ;
	else
	{
		printf("==========fifo_print==========\n") ;
		for ( int i = 0 ; i < fifo->count ; i++ )
		{
			printf("%d\n",fifo->item[i]) ;
		}
	}
}
