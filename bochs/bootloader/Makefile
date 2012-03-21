.PHONY: all clean mrproper

##########

all: bootloader.img

bootloader.img: grub/stage1 grub/stage2
	cat $^ > $@

##########

clean:

mrproper: clean
	rm -f bootloader.img
