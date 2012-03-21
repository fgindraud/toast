.PHONY: all img bootloader clean mrproper

DIRS	=	img bootloader

all: img 
	setxkbmap us; bochs; setxkbmap fr -variant oss

img: bootloader
	make -C $@

bootloader:
	make -C $@

clean:
	for d in $(DIRS); do make -C $$d clean; done

mrproper:
	for d in $(DIRS); do make -C $$d mrproper; done
