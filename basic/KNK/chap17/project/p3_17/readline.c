#include <stdio.h>

int readline(char *str, int strlen) {
	int ch, len = 0;
	while ((ch = getchar()) != '\n' && len < strlen) {
		*str++ = ch;
		len++;
	}
	*str = '\0';
	return len;
}
