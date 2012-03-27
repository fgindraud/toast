.global entry_point

##### Grub multiboot handling #####
# Should check multiboot spec

.set MB_ALIGN,		1 << 0
.set MB_MEMINFO,	1 << 1
.set MB_FLAGS,		MB_ALIGN | MB_MEMINFO
.set MB_MAGIC,		0x1BADB002
.set MB_CKSUM,		- (MB_MAGIC + MB_FLAGS)

.section .text

.align 4
.long	MB_MAGIC
.long MB_FLAGS
.long MB_CKSUM

##### Stack #####

.section .bss

.set STACK_SIZE,	0x4000
.comm stack, STACK_SIZE, 32

##### Start #####
.section .text

entry_point:
	movl $(stack + STACK_SIZE), %esp # prepare stack
	push %eax	# multiboot magic number should be here
	push %ebx	# multiboot structure pointer

	call kmain	# kernel
	
	cli	# disable interrupts
stop:
	hlt
	jmp stop
