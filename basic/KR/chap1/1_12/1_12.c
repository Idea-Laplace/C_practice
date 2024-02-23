/* Write a program that prints its input one word per line */

#include <stdio.h>

#define IN 1
#define OUT 0


int main(void) {
	int ch, state;

	state = OUT;

	while ((ch = getchar()) != EOF) {
		if (!(ch == '\n' || ch == '\t' || ch == ' ')) {
			state = IN;
			putchar(ch);
		} else if (state == IN) {
			state = OUT;
			putchar('\n');
		} else
			;
	}

	return 0;
}

