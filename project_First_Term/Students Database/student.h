/*
 * student.h
 *
 *  Created on: Sep 24, 2022
 *      Author: karim
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdint.h>
#include "stdbool.h"
#define initFifo	0
#define addStudent_details_from_file	1
#define addStduent_details_manually	2
#define findStudent_by_giving_id	3
#define findStuden_by_first_name	4
#define findStudentRegisteredInCoursre	5
#define countOfStudent	6
#define deleteStudent	7
#define updataStudent	8
#define exit_programm	10
#define printAll_students	9
#define MAX_LINE	1000

#define number_of_student	50
#define Number_of_courses	5
#define Clean_Buffer { fflush(stdout); \
					   fflush(stdin) ; }
typedef struct {
	uint8_t First_name[10]  ;
	uint8_t Second_name[10] ;
	uint32_t ID ;
	float gpa;
	uint32_t courses[Number_of_courses];

} Sperson ;

typedef struct {
	Sperson* head ;
	Sperson* base ;
	uint32_t* count ;
	Sperson student[number_of_student] ;
} student_info ;

typedef enum {
	fifo_no_error ,
	fifo_full ,
	fifo_NULL ,
	fifo_empty
} fifo_status_e ;
fifo_status_e init_fifo ( student_info* person1 , uint32_t* temp , uint32_t *r ) ;
fifo_status_e add_student_details_from_file ( student_info* person1 , uint32_t *r ) ;
fifo_status_e add_stduent_details_manually ( student_info* person1 , uint32_t *r ) ;
fifo_status_e find_student_by_giving_id( student_info* person1 , uint32_t *r) ;
fifo_status_e find_studen_by_first_name ( student_info* person1 , uint32_t *r) ;
fifo_status_e find_student_registered_in_coursre ( student_info* person1 , uint32_t *r) ;
fifo_status_e count_of_student ( student_info* person1 , uint32_t *r ) ;
fifo_status_e delete_student ( student_info* person1 , uint32_t *r ) ;
fifo_status_e updata_student ( student_info* person1 , uint32_t *r ) ;
fifo_status_e print_all_students ( student_info* person1 , uint32_t *r ) ;



#endif /* STUDENT_H_ */
