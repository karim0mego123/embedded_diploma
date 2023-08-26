#include "SPI.h"
#include "LCD.h"
#include "EXTI.h"
#include "FreeRTOS.h"
#include "task.h"


#define TASKA_STACK_SIZE 100
#define TASKB_STACK_SIZE 100

volatile uint8_t flag_Task_A = 0 ;
volatile uint8_t flag_Task_B = 0 ;
volatile uint8_t flag  ;

extern int _estack ;

unsigned int _S_MSP = &_estack ;
unsigned int _E_MSP ;

unsigned int _S_PSP_TA ;
unsigned int _E_PSP_TA ;

unsigned int _S_PSP_TB ;
unsigned int _E_PSP_TB ;


#define SWITCH_CPU_ACCESS_PRIVILEGE_TO_UNPRIVILEGE		  __asm("MRS R3,CONTROL \n\t orr r3,r3,#0x1 \n\t msr CONTROL,r3 \n\t ")


#define SWITCH_CPU_ACCESS_UNPRIVILEGE_TO_PRIVILEGE		__asm(  "mrs r3,CONTROL \n\t lsr r3,r3,#0x1 \n\t lsl r3,r3,#0x1 \n\t msr CONTROL,r3 \n\t")


#define OS_SET_PSP(Add) 						__asm volatile ("mov r0,%0 \n\t msr PSP,r0 \n\r" : : "r"(Add))
#define OS_SWITCH_SP_MSP						__asm volatile ("MRS R0,CONTROL \t\n AND R0,R0,#0x5 \t\n MSR CONTROL,R0")
#define OS_SWITCH_SP_PSP						__asm volatile ("MRS R0,CONTROL \t\n ORR R0,R0,#0x2 \t\n MSR CONTROL,R0")
#define OS_GENERATE_INTERRUPT      				__asm volatile ("SVC #0x3")

void SVC_Handler ()
{
	SWITCH_CPU_ACCESS_UNPRIVILEGE_TO_PRIVILEGE ;
}


int TASK_A(int a , int b )
{
	return a+b ;
}
int TASK_B(int a , int b )
{
	return a+b ;
}
void EXTI9_CALLBACK(void)
{
	if(flag==0)
	{
		flag_Task_A = 1 ;
		flag = 1 ;
	}
	else if(flag==1)
	{
		flag_Task_B = 1 ;
		flag = 0 ;
	}
}
void Main_Os()
{
	_E_MSP = _S_MSP - 512 ;

	_S_PSP_TA = _E_MSP - 8 ;
	_E_PSP_TA = _S_PSP_TA - TASKA_STACK_SIZE ;

	_S_PSP_TB = _E_PSP_TA - 8 ;
	_E_PSP_TB = _S_PSP_TB - TASKB_STACK_SIZE ;
	while(1)
	{

		__asm("nop") ;

		if (flag_Task_A == 1)
		{

			// Set PSP Register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TA) ;
			// SP -> PSP
			OS_SWITCH_SP_PSP ;
			// Switch from Privileged to UnPrivileged
			SWITCH_CPU_ACCESS_PRIVILEGE_TO_UNPRIVILEGE ;
			TASK_B(10,20) ;
			// Switch from UnPrivileged to Privileged
			OS_GENERATE_INTERRUPT ;
			// SP -> MSP
			OS_SWITCH_SP_MSP ;
			__asm("nop") ;


		}
		else if(flag_Task_B==1)
		{

			OS_SET_PSP(_S_PSP_TB) ;
			OS_SWITCH_SP_PSP ;
			SWITCH_CPU_ACCESS_PRIVILEGE_TO_UNPRIVILEGE ;
			TASK_B(10,20) ;
			OS_GENERATE_INTERRUPT ;
			OS_SWITCH_SP_MSP ;
		}
	}

}

int main ()
{
	/* RCC Init */
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	EXTI_PinConfig_t EXTI_CFG ;
	EXTI_CFG.EXTI_PIN = EXTI0PA0 ;
	EXTI_CFG.IRQ_EN  =  EXTI_IRQ_Enable ;
	EXTI_CFG.P_IRQ_CallBak = EXTI9_CALLBACK ;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_RisingAnd_Falling;
	MCAL_EXTI_GPIO_Init(&EXTI_CFG) ;

	NVIC_IRQ23_EXTI5_9_Enable ;




	Main_Os();



	while(1); // Shall not return from MainOS

	return 0;

}
