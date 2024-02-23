/* Write a program to print a histogram of th length of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical orientation
 * is more challenging.
 */

#include <stdio.h>

#define MAX_LEN 20
#define IN 1
#define OUT 0

int main(void) {
	int word_length[MAX_LEN + 1];
	int ch, i, j, state, wl;

	for (i = 0; i < MAX_LEN + 1; i++)
		word_length[i] = 0;

	state = OUT;
	wl = 0;

	while ((ch = getchar()) != EOF) {
		if (!(ch == ' ' || ch == '\t' || ch == '\n')) {
			state = IN;
			wl++;
		} else if (state == IN) {
			state = OUT;
			if (wl > MAX_LEN)
				word_length[MAX_LEN]++;
			else
				word_length[wl - 1]++;
			wl = 0;
		}
	}

	// When EOF comes just after a word.
	if (state == IN) {
		if (wl >= MAX_LEN)
			word_length[MAX_LEN]++;
		else
			word_length[wl - 1]++;
	}

	printf("Number of words of length 1 ~ 20\n");
	for (i = 0; i < MAX_LEN; i++) {
		printf("%3d| ", i + 1);
		for (j = 0; j < word_length[i]; j++)
			putchar('*');
		putchar('\n');
	}
	printf("20+| ");
	for (j = 0; j < word_length[MAX_LEN]; j++)
		putchar('*');
	putchar('\n');

	return 0;
}

