.PHONY: all clean mrproper

KER	=	../src/kernel.bin

all: $(KER)
	qemu-system-i386 -kernel $<

clean:

mrproper: clean
