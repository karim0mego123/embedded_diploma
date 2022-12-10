/*
 * Bit_Manipulation.h
 *
 * Created: 11/26/2022 12:06:00 PM
 *  Author: karim
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_


#define SET_REG(Reg) Reg=0xFF
#define CLEAR_REG(Reg) Reg=0x00
#define TOOGLE_REG(Reg) Reg^=0xFF
#define ASSIGN_REG(Reg,Value) Reg=Value
#define SET_BITS_REG(Reg,Mask) Reg|=(Mask)
#define CLEAR_BITS_REG(Reg,Mask) Reg=(Reg&(~Mask))
#define SET_BIT(Reg,bit) Reg|=(1<<bit)
#define CLEAR_BIT(Reg,bit) Reg=(Reg&(~(1<<bit)))
#define TOOGLE_BIT(Reg,bit) Reg^=(1<<bit)
#define READ_BIT(Reg,bit) ((Reg>>bit)&1)


#endif /* BIT_MANIPULATION_H_ */