/*
 * String utils
 */
#include <string.h>

unsigned strlen (char *text) {
	unsigned len = 0;
	while (*text != '\0') {
		++len;
		++text;
	}
	return len;
}

