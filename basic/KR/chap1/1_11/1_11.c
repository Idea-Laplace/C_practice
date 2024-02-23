/* How would you test the word count program? What kinds of input are
 * most likely to uncover bugs if there is any? */


/* Answer: We can use this program with input redirection : $./word_count <{filename}.
 * If the input is too large, nc would find itself overflow.*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
	int ch, nl, nw, nc;
	state = OUT;
	nl = nw = nc = 0;

	while ((ch = getchar()) != EOF) {
		nc++;
		if (c == '\n')
			nl++;
		if (ch == ' ' || ch == '\t' || ch == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			nw++;
		}
	}
	printf("Lines:     %-d\n", nl);
	printf("Words:     %-d\n", nw);
	printf("Character: %-d\n", nc);

	return 0;
}

