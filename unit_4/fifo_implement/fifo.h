/*
 * fifo.h
 *
 *  Created on: Sep 22, 2022
 *      Author: karim
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include "stdint.h"
#define element_type	uint8_t
#define array_size		5
typedef struct {
	uint32_t length ;
	uint32_t count ;
	element_type* head ;
	element_type* tail ;
	element_type* base ;
} fifo_buf_t ;
typedef enum {
	fifo_no_error ,
	fifo_full ,
	fifo_empty ,
	fifo_null
} fifo_status_t;
fifo_status_t fifo_init ( fifo_buf_t* fifo , element_type* buf , uint32_t lenght ) ;
fifo_status_t fifo_enqueue ( fifo_buf_t* fifo ) ;
fifo_status_t fifo_dequeue ( fifo_buf_t* fifo , element_type* buf ) ;
fifo_status_t fifo_is_full ( fifo_buf_t* fifo ) ;
void fifo_print ( fifo_buf_t* fifo , element_type* buf ) ;

#endif /* FIFO_H_ */
