/* Print longest input line. */

#include <stdio.h>

#define MAXLINE 1000 /* Maximum input line size */

int my_getline(char *line, int maxline);
void copy(char to[], char from[]);

int main(void) {
	int len;
	int max;
	char line[MAXLINE + 1];
	char longest[MAXLINE + 1];

	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	
	if (max > 0) /* There was a line. */
		printf("%s", longest);

	return 0;
}

int my_getline(char *line, int maxline) {
	int c, i;

	for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';
	return i;
}


void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}


