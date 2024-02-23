// Write a program to copy its input to output,
// replacing each string of one or more blanks by a single blank.

#include <stdio.h>

int main(void) {
	int ch;
	int in_space = 0;

	while ((ch = getchar()) != EOF) {
		if (in_space == 1 && (ch == '\t' || ch == ' '))
			;
		else if (ch == '\t' || ch == ' ') {
			putchar(' ');
			in_space = 1;
		} else {
			putchar(ch);
			in_space = 0;
		}
	}
	return 0;
}

