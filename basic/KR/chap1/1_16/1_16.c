/* Print logest input line. */

#include <stdio.h>

#define MAXLINE 11 /* Maximum input line size */

int my_getline(char *line, int maxline);
void copy(char to[], char from[]);

int main(void) {
	int len;
	int max;
	char line[MAXLINE + 1 + 1];
	char longest[MAXLINE + 1 + 1];

	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	
	if (max > 0) /* There was a line. */
		printf("%d:%s", max, longest);

	return 0;
}

int my_getline(char *line, int maxline) {
	int i, ch, effective;

	for (i = effective = 0; (ch = getchar()) != EOF && ch != '\n'; i++)
		if (i < maxline) {
			line[i] = ch;
			effective++;
		}

	if (ch == '\n') {
		line[effective++] = '\n';
		i++;
	}

	line[effective] = '\0';

	return i;
}


void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}


