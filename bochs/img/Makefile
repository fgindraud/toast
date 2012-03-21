.PHONY: all clean mrproper

KERNEL	=	../../src/kernel.bin
BLD	=	../bootloader/bootloader.img

IMG	=	kernel.img

##########

all: $(IMG)

$(IMG): $(BLD) pad $(KERNEL)
	cat $^ > $(IMG)

pad: $(BLD) $(KERNEL)
	./create_pad $@ $^

#########

clean:
	rm -f pad

mrproper: clean
	rm -f $(IMG)
