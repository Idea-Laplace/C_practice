/* Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines. */

#include <stdio.h>

#define BUFFER_SIZE 1000

int cleave_trailing_blank(char *line, int maxline);

int main(void) {
	char line[BUFFER_SIZE + 1];
	int len;

	while ((len = cleave_trailing_blank(line, BUFFER_SIZE)) >= 0)
		if (len > 0)
			printf("%s\n", line);

	return 0;
}

int cleave_trailing_blank(char *line, int maxline) {
	int i, j, ch;

	for (i = 0; i < BUFFER_SIZE && (ch = getchar()) != EOF && ch != '\n'; i++)
		line[i] = ch;


	for (j = i; j > 0 && (line[j - 1] == ' ' || line[j - 1] == '\t'); j--)
		;
	line[j] = '\0';

	if (ch == EOF)
		return -1;

	return j;
}


