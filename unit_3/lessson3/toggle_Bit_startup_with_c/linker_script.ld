

MEMORY
{
	FLASH(RX) : ORIGIN = 0X08000000, LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0X20000000, LENGTH = 20K
}
SECTIONS
{
	.text : {
			*(.vectors*)
			*(.text*)
			*(.rodata)
			_E_TEXT = . ;
	}> FLASH
 
	.data : {
			_S_DATA = . ;
			*(.data)
			. = ALIGN(4) ;
			_E_DATA = . ;
	}> FLASH
	.bss : {
			_S_BSS = . ;
			*(.bss)
			. = ALIGN(4) ;
			_E_BSS = . ;
			. = . + 0x1000 ;
			_STACK_TOP = . ;
	}> SRAM
}