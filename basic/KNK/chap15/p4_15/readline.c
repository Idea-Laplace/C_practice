#include <stdio.h>
#include "readline.h"


int read_line(char str[], int string_length) {
	int ch;
	int i = 0;

	while ((ch = getchar()) != '\n')
		if (i < string_length)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
