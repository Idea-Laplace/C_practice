#include <stdio.h>
#include "readline.h"

int readline(char *line, int max_len) {
	int len = 0;
	char ch;

	while((ch = getchar()) != '\n') {
		if (len < max_len) {
			*line++ = ch;
			len++;
		}
	}
	*line = '\0';

	return len;
}
