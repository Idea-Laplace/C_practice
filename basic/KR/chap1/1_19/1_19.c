/* Write a function revers(s) that reverses the character string s.
 * Use it to write that reverses its input a line at a time. */

#include <stdio.h>

#define BUFFER_SIZE 1000

int reverse(char *line, int buffer_size);

int main(void) {
	char line[BUFFER_SIZE + 1];

	while (reverse(line, BUFFER_SIZE) != EOF)
		printf("%s\n", line);

	return 0;
}

int reverse(char *line, int buffer_size) {
	int i, j, temp, ch;

	for (i = 0; i < buffer_size && (ch = getchar()) != EOF && ch != '\n'; i++)
		line[i] = ch;

	line[i] = '\0';

	for (j = 0; j < i / 2; j++) {
		temp = line[j];
		line[j] = line[i - j -1];
		line[i - j - 1] = temp;
	}

	return ch;
}

