// Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main(void) {
	unsigned long nw;
	int c;

	nw = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n' || c == '\t' || c == ' ')
			++nw;

	printf("White characters: %lu\n", nw);

	return 0;
}

