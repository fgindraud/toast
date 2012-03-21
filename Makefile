.PHONY: all kernel bootloader img simul

DIRS	=	img src bootloader bochs

##########

all: img

img: kernel bootloader
	make -C img

bootloader:
	make -C bootloader

kernel:
	make -C src

#########

simul: img
	make -C bochs

#########

clean:
	for d in $(DIRS); do make -C $$d clean; done

mrproper:
	for d in $(DIRS); do make -C $$d mrproper; done

