#include <stdio.h>
#include "read.h"

int read_line(char *str, size_t len_str) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < len_str)
			str[i++] = ch;
		if (i == len_str)
			str[i++] = '*';
	}

	str[i] = '\0';
	return i;
}
	

