#include <stdio.h>

// int fputc(int c, FILE *stream);
// int putc(int c, FILE *stream);
// int putchar(int c),  // #define putchar(c) putchar((c), stdout)

// int fgetc(FILE *stream);
// int getc(FILE *stream);
// int getchar(void)  // #define getchar() getc(stdin)
// int ungetc(int c, FILE *stream);  // Time machine

#define LEN 30

int main(void) {
	char str[LEN + 1] = {'\0'};
	char ch;


	while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
		if (ch == 'a') {
			ungetc(ch, stdin);
			fputc('\n', stdout);
			ch = getchar();
			continue;
		}

		fputc(ch, stdout);
	}

	return 0;
}





