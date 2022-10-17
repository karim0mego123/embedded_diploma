/*
 * C_A.c
 *
 *  Created on: Oct 15, 2022
 *      Author: karim
 */
#include "c_a.h"
int generate_random ( int i , int r , int count ) ;
int speed  ;
int distance ;
int thershold = 50 ;
enum {
	waiting ,
	driving

} ca_Status_id ;

void (*PTR_STATUS)() ;

status_define(CA_waiting)
{
	ca_Status_id = waiting ;
	speed = 0 ;
	distance = generate_random ( 45 , 55 , 1 )  ;
	(distance <= thershold)? (PTR_STATUS = status(CA_waiting) ) : (PTR_STATUS = status(CA_driving) ) ;
	printf("ca_waiting state distane = %d speed = %d\n",distance,speed) ;
}
status_define(CA_driving)
{
	ca_Status_id = driving ;
	speed = 30 ;
	distance = generate_random ( 45 , 55 , 1 )  ;
	(distance <= thershold)? (PTR_STATUS  = status(CA_waiting) ) : (PTR_STATUS = status(CA_driving) ) ;
	printf("CA_driving state distane = %d speed = %d\n",distance,speed) ;
}
int generate_random ( int l , int r , int count )
{
	int rand_num , i  ;
	for ( i = 0 ; i < count ; i++ )
		rand_num = ( rand()% (r-l+1) ) + l ;
	return rand_num ;
}
