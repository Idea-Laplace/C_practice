/* Count lines, words, and characters in input. */

#include <stdio.h>

#define IN 1  // Inside a word.
#define OUT 0 // Outside a word.

int main(void) {
	int ch, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((ch = getchar()) != EOF) {
		nc++;

		if (ch == '\n')
			nl++;
		if (ch == ' ' || ch == '\t' || ch == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			nw++;
		}
	}

	printf("Lines:      %-5d\n", nl);
	printf("Words:      %-5d\n", nw);
	printf("Characters: %-5d\n", nc);

	return 0;
}
