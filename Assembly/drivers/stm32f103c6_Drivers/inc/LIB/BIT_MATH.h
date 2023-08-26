/*
 * BIT_MATH.h
 *
 *  Created on: Mar 25, 2023
 *      Author: karim
 */

#ifndef INC_LIB_BIT_MATH_H_
#define INC_LIB_BIT_MATH_H_

#define SET_BIT(REG,VAL)          	REG |=  (1 << (VAL))
#define CLEAR_BIT(REG,VAL)          REG &= ~(1 << (VAL))
#define SET_REG(REG,VAL)			REG = VAL
#define CLEAR_REG(REG)				REG = 0
#define GET_BIT(REG,VAL)        	((REG >> VAL) & 1  )
#define TOG_BIT(REG,VAL)       	    REG ^=  (1 << (VAL))


#endif /* INC_LIB_BIT_MATH_H_ */
