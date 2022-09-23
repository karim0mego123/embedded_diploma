/*
 * fifo.c
 *
 *  Created on: Sep 22, 2022
 *      Author: karim
 */
#include "fifo.h"
#include "stdlib.h"
fifo_status_t fifo_init ( fifo_buf_t* fifo , element_type* buf , uint32_t lenght )
{
	if ( buf == NULL )
	{
		printf("init lifo pointer is NULL\n" ) ;
		exit(1) ;
	}
	fifo->base = buf ;
	fifo->head = buf ;
	fifo->tail = buf ;
	fifo->length = lenght ;
	fifo->count = 0 ;
	return fifo_no_error ;
}
fifo_status_t fifo_enqueue ( fifo_buf_t* fifo )
{
	element_type buf ;
	if ( !fifo->base || !fifo->head || !fifo->tail )
	{
		printf("init pointer NULL\n") ;
	}
	if ( fifo_is_full(fifo) == fifo_full )
	{
		printf("fifo is full\n") ;
	}
	printf("enter element to enqueue = " ) ;
	fflush (stdin) ; fflush(stdout) ;
	scanf("%c",&buf) ;
	*(fifo->head) = buf ;
	fifo->count++ ;
	if ( fifo->head == fifo->base + ( fifo->length * sizeof( element_type ) ) )
		fifo->head = fifo->base ;
	else
		fifo->head++ ;
	return fifo_no_error ;
}
fifo_status_t fifo_dequeue ( fifo_buf_t* fifo , element_type* buf )
{
	if ( !fifo->base || !fifo->head || !fifo->tail )
		return fifo_null ;
	if ( fifo->count == 0 )
		return fifo_empty ;
	*buf = *fifo->tail ;
	fifo->count-- ;
	if ( fifo->tail == fifo->base + ( fifo->length * sizeof( element_type) ) )
		fifo->tail = fifo->base ;
	else
		fifo->tail++ ;
	return fifo_no_error ;
}
fifo_status_t fifo_is_full ( fifo_buf_t* fifo )
{
	if ( !fifo->base || !fifo->head || !fifo->tail )
		return fifo_null ;
	if ( fifo->count == fifo->length )
		return fifo_full ;
	return fifo_no_error ;

}
void fifo_print ( fifo_buf_t* fifo , element_type* buf )
{
	if ( fifo->count == 0 )
		printf("fifo is empty\n") ;
	else
	{
		buf = fifo->tail ;
		printf("==========fifo_print==========\n") ;
		for ( int i = 0 ; i < fifo->count ; i++ )
		{
			printf("%c\n",*buf) ;
			buf++ ;
		}
	}
}
