cc = gcc
#rr = -mcpu=arm926ej-s -g 
pp =  $(INCLUDES) -Wall -o0 -g3 .
INCLUDES = -I C:\Users\karim\workspace\p\app C:\Users\karim\workspace\p\card C:\Users\karim\workspace\p\server C:\Users\karim\workspace\p\terminal
LIBS = 
as =  $(wildcard *.c)
obj = $(as:.c=.o)
asm = $(wildcard *.s)
asmobj = $(asm:.s=.o)
project_name = PaymentMathod
all : $(project_name).exe
	@echo "==== Build is done ===="
	
$(project_name).exe : %.c
	$(cc) $(pp) -c $< -o $@
	
#$(project_name).elf : $(obj) $(asmobj)
#	$(cc)ld.exe -T linker_script.ld $(LIBS) $(obj) $(asmobj) -o $@
	

	
clean-all :
	rm *.o *.bin *.elf
	
clean :
	rm *.bin *.elf