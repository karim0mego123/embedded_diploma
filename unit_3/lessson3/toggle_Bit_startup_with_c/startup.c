#include "stdint.h"
extern uint32_t _stackTop_;
extern int main(void);
extern unsigned int _STACK_TOP ;
extern unsigned int _E_TEXT ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS ;
extern unsigned int _E_BSS ;

void reset_handler(void);
void default_handler(void)
{
		reset_handler() ;
}
void NMI_handler(void)__attribute__((weak, alias("default_handler")));
void HardFault_handler(void)__attribute__((weak, alias("default_handler")));
void MMFault_handler(void)__attribute__((weak, alias("default_handler")));
void BusFault_handler(void)__attribute__((weak, alias("default_handler")));
void UsageFault_handler(void)__attribute__((weak, alias("default_handler")));

uint32_t vectors[] __attribute__((section(".vectors")))= 
{
	//(uint32_t)0x20001000,
	(uint32_t)&_STACK_TOP,
	(uint32_t)&reset_handler,
	(uint32_t)&NMI_handler,
	(uint32_t)&HardFault_handler,
	(uint32_t)&MMFault_handler,
	(uint32_t)&BusFault_handler,
	(uint32_t)&UsageFault_handler
};
void reset_handler (void)
{
	uint32_t i = 0 ; 
	uint32_t data_size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA ; 
	uint8_t *ptr1_in_flash = (uint8_t*)&_E_TEXT ; 
	uint8_t *ptr2_in_ram = (uint8_t*)&_S_DATA ; 
	for (  i = 0 ; i < data_size ; i++ )
	{
		*((uint8_t*)ptr2_in_ram++) = *((uint8_t*)ptr1_in_flash++) ; 
	}
	uint32_t bss_size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS ; 
	uint8_t*ptr_bss = (uint8_t*)(&_S_BSS) ; 
	for (  i = 0 ; i < bss_size ; i++ )
	{
		*((uint8_t*)ptr_bss++) = (uint8_t) 0 ;  
	}
	main() ; 
}