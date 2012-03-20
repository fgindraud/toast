.PHONY: all kernel bootloader

KER_D	=	src
BLD_D	=	bootloader
DIRS	=	$(KER_D) $(BLD_D)

IMG	=	kernel.img

##########

all: $(IMG)

$(IMG): kernel bootloader
	dd if=/dev/zero of=pad bs=1 count=750
	cat $(BLD_D)/bootloader.img pad $(KER_D)/kernel.bin > $(IMG)
	rm -f pad

bootloader:
	make -C $(BLD_D)

kernel:
	make -C $(KER_D)

#########

simul: $(IMG)
	make -C bochs

#########
