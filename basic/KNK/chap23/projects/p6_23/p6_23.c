/*
   Write a program that copies a text file from standard input, replacing
   each contral character other than '\n' by a question mark.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
	int ch;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			putchar(ch);
		else if (iscntrl(ch))
			putchar('?');
		else
			putchar(ch);
	}

	return 0;
}
