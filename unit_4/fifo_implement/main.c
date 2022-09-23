/*
 * main.c
 *
 *  Created on: Sep 22, 2022
 *      Author: karim
 */
#include "fifo.h"
#define enqueueStudent	1
#define dequeueStudent		2
#define exit_programm	4
#define print_fifo	3
#define true 	1
int main ()
{
	fifo_buf_t fifo_uart ;
	element_type uart_buffer[array_size] ;
	if ( fifo_init ( &fifo_uart , uart_buffer , 5 ) == fifo_no_error )
		printf("fifo init is done\n") ;
	uint32_t loc_choice ;
	while( true )
	{
		printf("1-enqueue student\n" ) ;
		printf("2-dequeue student\n") ;
		printf("3-print your lifo\n") ;
		printf("4-exit\n") ;
		printf("enter your choice = " ) ;
		fflush (stdin) ; fflush(stdout) ;
		scanf("%d",&loc_choice) ;
		switch (loc_choice)
		{
		case enqueueStudent :
			if ( fifo_enqueue( &fifo_uart  ) == fifo_no_error )
				printf("fifo enqueue is done\n") ;
			break ;
		case dequeueStudent :
			if ( fifo_dequeue ( &fifo_uart , uart_buffer ) == fifo_empty )
				printf("lifo is empty\n") ;
			break ;
		case print_fifo :
			fifo_print ( &fifo_uart , uart_buffer ) ;
					break ;
			case exit_programm :
				return fifo_no_error ;
			default :
				printf("you have entered wrong choice " ) ;
		}
	}
	return fifo_no_error ;
}

