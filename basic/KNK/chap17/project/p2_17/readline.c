#include <stdio.h>
#include "readline.h"


int readline(char *str, int strlen) {
	char ch;
	int len = 0;
	while ((ch = getchar()) != '\n' && len < strlen) {
		*str++ = ch;
		len++;
	}
	return len;
}
