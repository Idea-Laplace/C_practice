#include <stdio.h>

int main(void) {
	int ch;
	int i = 1;

	printf("Enter any sentence.\n");
	while ((ch = getchar()) != EOF && ch != '\n') {
		if (i % 4 == 0) {
			ungetc(ch, stdin);
			ungetc(ch, stdin);
		}
		putchar(ch);
		i++;
	}
	printf("\n");

	printf("Testing ungetc...\n");
	ungetc(ch, stdin);
	putc(ch, stdout);

	ungetc(ch, stdin);

	putc(ch, stdout);

	return 0;
}



