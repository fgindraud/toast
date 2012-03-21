CC	=	i686-elf-gcc
LD	=	i686-elf-ld
AS	=	i686-elf-as

CFLAGS	=	-Wall -Wextra -Werror
LDFLAGS	=	-nostdlib -fno-builtin -nostartfiles -nodefaultlibs

################

.PHONY: all clean mrproper

################

OBJ=kernel.o

################

all: kernel.bin

kernel.o: kernel.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

loader.o: loader.s
	$(AS) -o $@ $<

kernel.bin: $(OBJ) linker.ld loader.o
	$(LD) -T linker.ld -o $@ $(OBJ) 

###############

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f kernel.bin

