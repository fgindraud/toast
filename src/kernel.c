unsigned strlen (char *text) {
	unsigned len = 0;
	while (*text != '\0') {
		++len;
		++text;
	}
	return len;
}

struct vr_cell {
	unsigned char letter;
	unsigned char color;
};

struct vr_mem {
	unsigned w;
	unsigned h;
	struct vr_cell *mem;
};

void vr_clear (struct vr_mem *mem) {
	unsigned i;
	unsigned limit = mem->w * mem->h;
	
	for (i = 0; i < limit; ++i) {
		struct vr_cell *cell = &mem->mem[i];
		cell->letter = ' ';
		cell->color = 0x07;
	}
}

void vr_setup (struct vr_mem *mem, void *addr, unsigned w, unsigned h) {
	mem->mem = (struct vr_cell*) addr;
	mem->w = w;
	mem->h = h;

	vr_clear (mem);
}

void vr_print (struct vr_mem *mem, char *text, unsigned color, unsigned w, unsigned h) {
	unsigned pos = h * mem->w + w;
	unsigned limit = mem->w * mem->h;

	while (*text != '\0') {
		if (pos >= limit)
			pos = 0;
		struct vr_cell *cell = &mem->mem[pos];
		cell->letter = *text;
		cell->color = color;

		++text;
		++pos;
	}
}

void vr_print_centered (struct vr_mem *mem, char *text, unsigned color, unsigned h) {
	unsigned len = strlen (text);
	unsigned w = 0;
	
	if (len <= mem->w)
		w = (mem->w - len) / 2;

	vr_print (mem, text, color, w, h);
}

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
