.PHONY: all kernel bochs qemu

DIRS	=	src bochs qemu

##########

all: kernel

kernel:
	make -C src

#########

bochs: kernel
	make -C $@

qemu: kernel
	make -C $@

#########

clean:
	for d in $(DIRS); do make -C $$d clean; done

mrproper:
	for d in $(DIRS); do make -C $$d mrproper; done

