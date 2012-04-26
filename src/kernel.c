#include <video.h>

/* -------------- */

void kmain (void * multiboot_data, unsigned magic_value) {

	/* Check magic value */
	if (magic_value != 0x2BADB002) {
		return;
	}

	/* Test */
	struct vr_mem vmem;

	vr_setup (&vmem, (void*) 0xB8000, 80, 25);

	vr_print_centered (&vmem, "Toast (Test OperAting SysTem) v0.1", 0x74, 0);
	vr_print_centered (&vmem, "Keyboard is not supported, so you can only shutdown the computer now...", 0x07, 3);

	(void) multiboot_data;
}
