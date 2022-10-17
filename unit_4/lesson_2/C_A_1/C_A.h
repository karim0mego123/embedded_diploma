/*
 * c_a.h
 *
 *  Created on: Oct 15, 2022
 *      Author: karim
 */

#ifndef C_A_H_
#define C_A_H_


#include "state.h"
#include "stdio.h"
#include "stdlib.h"

status_define(CA_driving) ;
status_define(CA_waiting) ;

extern void (*PTR_STATUS)() ;

#endif /* C_A_H_ */
