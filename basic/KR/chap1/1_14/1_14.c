/* Write a program to print a histogram of the frequencies of different characters in its input. */

#include <ctype.h>
#include <stdio.h>

#define CHAR 128

int main(void) {
	int ch;
	int chars[CHAR];
	int i, j;

	for (i = 0; i < CHAR; i++)
		chars[i] = 0;

	while ((ch = getchar()) != EOF) {
		if (!(isprint(ch)))
			;
		else
			chars[ch]++;
	}

	for (i = 0; i < CHAR; i++) {
		if (!isprint(i) || chars[i] == 0)
			continue;
		else if (i == ' ')
			printf("\' \'|");
		else if (i == '\t')
			printf(" \\t|");
		else if (i == '\n')
			printf(" \\n|");
		else 
			printf(" %c |", i);

		for (j = 0; j < chars[i]; j++)
			putchar('*');
		putchar('\n');
	}

	return 0;
}


