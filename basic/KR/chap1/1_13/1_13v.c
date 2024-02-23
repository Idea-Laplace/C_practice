/* Write a program to print a histogram of th length of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical orientation
 * is more challenging.
 */

#include <stdio.h>

#define MAX_LEN 20
#define HEIGHT 30
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

	printf("Num\n");
	printf("%d+| ", HEIGHT);
	for (i = 0; i <= MAX_LEN; i++) {
		if (word_length[i] - HEIGHT > 0)
			printf("~ ");
		else
			putchar(' ');
	}
	putchar('\n');
	
	for (i = HEIGHT; i > 0; i--) {
		printf("%3d| ", i);
		for (j = 0; j < MAX_LEN + 1 ; j++) {
			if (word_length[j] - i >= 0)
				printf("* ");
			else
				printf("  ");
		}
		putchar('\n');
	}

	printf("----");
	for (i = 0; i < MAX_LEN + 1; i++)
		printf("--");
	putchar('-');
	putchar('\n');

	printf("    ");
	for (i = 0; i < MAX_LEN; i++)
		printf("%2d", i + 1);
	printf("20+\n");

	return 0;
}
