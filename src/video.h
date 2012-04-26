/*
 * Video Ram basic handling
 */
#ifndef H_VIDEO
#define H_VIDEO

/*
 * Video text mode pixel
 */
struct vr_cell {
	unsigned char letter;
	unsigned char color;
};

/*
 * Video memory handler
 */
struct vr_mem {
	unsigned w;
	unsigned h;
	struct vr_cell *mem;
};

/* Setup handler struct */
void vr_setup (struct vr_mem *mem, void *addr, unsigned w, unsigned h);

/* Reset screen */
void vr_clear (struct vr_mem *mem);

/* Print */
void vr_print (struct vr_mem *mem, char *text, unsigned color, unsigned w, unsigned h);
void vr_print_centered (struct vr_mem *mem, char *text, unsigned color, unsigned h);

#endif
