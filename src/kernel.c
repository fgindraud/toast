
void kmain (void * multiboot_data, unsigned magic_value) {

	/* Check magic value */
	if (magic_value != 0x2BADB002) {
		return;
	}
	
	/* Test */
	unsigned char *video = (unsigned char*) 0xB8000;

	video[0] = 'A';
	video[1] = 0x07;

	(void) multiboot_data;
}
