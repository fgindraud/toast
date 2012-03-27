ENTRY(entry_point)

OUTPUT_FORMAT(elf32-i386)

STARTUP(loader.o)

pagesize = 0x1000;
kernel_pos = 0x100000;

SECTIONS
{
	. = kernel_pos;

	.text ALIGN (pagesize) :
	{
		*(.text)
		*(.rodata)
	}

	.data ALIGN (pagesize) :
	{
		*(.data)
	}

	.bss ALIGN (pagesize) :
	{
		*(.bss)
	}

	/DISCARD/ :
	{
		*(.comment)
		*(.eh_frame)
	}
}
