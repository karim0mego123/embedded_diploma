cc = arm-none-eabi-
rr = -mcpu=arm926ej-s -g 
pp =  -I .
LIBS =
as =  $(wildcard *.c)
obj = $(as:.c=.o)
asm = $(wildcard *.s)
asmobj = $(asm:.s=.o)
project_name = learn-in-depth
all : $(project_name).bin
	@echo "==== Build is done ===="
startup.o : startup.s
	$(cc)as.exe $(rr) $< -o $@
	
%.o : %.c
	$(cc)gcc.exe $(pp)  $(rr) -c $< -o $@
	
$(project_name).elf : $(obj) $(asmobj)
	$(cc)ld.exe -T linker_script.ld $(LIBS) $(obj) $(asmobj) -o $@
	
$(project_name).bin : $(project_name).elf
	$(cc)objcopy.exe -O binary $< $@
	
clean-all :
	rm *.o *.bin *.elf
	
clean :
	rm *.bin *.elf