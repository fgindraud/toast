CC	=	i686-elf-gcc
LD	=	i686-elf-ld
AS	=	i686-elf-as

CFLAGS	=	-Wall -Wextra -Werror -I.
LDFLAGS	=	-nostdlib -fno-builtin -nostartfiles -nodefaultlibs

################

.PHONY: all clean mrproper

################

LINK_OBJ	=	kernel.o string.o video.o
OBJ	=	$(LINK_OBJ) loader.o

################

all: kernel.bin

%.o: %.c $(wildcard *.h)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

loader.o: loader.s
	$(AS) -o $@ $<

kernel.bin: $(OBJ) linker.ld
	$(LD) -T linker.ld -o $@ $(LINK_OBJ) 

###############

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f kernel.bin

