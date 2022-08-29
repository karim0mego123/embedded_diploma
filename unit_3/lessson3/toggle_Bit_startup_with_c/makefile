cc = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -gdwarf-2 -mthumb
INCS =  -I .
LIBS =
SRC =  $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name = learn-in-depth_cortexM4
all : $(project_name).bin
	@echo "==== Build is done ===="
	
%.o : %.c
	$(cc)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@
	
$(project_name).elf : $(OBJ) $(ASOBJ)
	$(cc)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	
$(project_name).bin : $(project_name).elf
	$(cc)objcopy.exe -O binary $< $@
	
clean-all :
	rm *.o *.bin *.elf
	
clean :
	rm *.bin *.elf