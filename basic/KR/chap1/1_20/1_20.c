/* Write a program 'detab' that replaces tabs in the 
 * input with the proper number of blanks to space to 
 * the next stop. Assume a fixed set of tabstop, say
 * every n columns. Should n be a variable or a symbolic
 * parameter? */

#include <stdio.h>

#define TABSTOP 4

int main(void) {
	int ch;
	int pos, num_blank;

	pos = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == '\t') {
			num_blank = TABSTOP - pos % TABSTOP;
			for (int i = 0; i < num_blank; i++) {
				putchar(' ');
				pos++;
			}
		} else if (ch == '\n') {
			putchar(ch);
			pos = 0;
		} else {
			putchar(ch);
			pos++;
		}
	}

	return 0;
}

