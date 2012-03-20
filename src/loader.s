.global entry_point

##### Grub multiboot handling #####
# Should check multiboot spec

.set ALIGN,		1 << 0
.set MEMINFO,	1 << 1
.set FLAGS,		ALIGN | MEMINFO
.set MAGIC,		0x1BADB002
.set CKSUM,		- (MAGIC + FLAGS)

.section .rodata

.align 4
.long	MAGIC
.long FLAGS
.long CKSUM

##### Stack #####

.section .bss

.set STACKSIZE,	0x4000
.comm stack, STACKSIZE, 32

##### Start #####
.section .text

entry_point:
	movl $(stack + STACKSIZE), %esp # prepare stack
	push %eax	# multiboot magic number should be here
	push %ebx	# multiboot structure pointer

	call kmain	# kernel
	
	cli	# dont know, check IA32
stop:
	hlt	# same
	jmp stop
