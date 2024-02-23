// Write a program to print all input lines that are longer than designated number of characters.


#include <stdio.h>

#define MAXLEN 1000
#define LINE_FEED 1
#define MINIMUM 30

int my_getline(char *line, int maxline);

int main(void) {
	int len;
	char line[MAXLEN + LINE_FEED + 1];

	while ((len = my_getline(line, MAXLEN)) > 0)
		if (len > MINIMUM)
			printf("%s", line);

	return 0;
}

int my_getline(char *line, int maxline) {
	int i, ch;

	for (i = 0; i < maxline && (ch = getchar()) != EOF && ch != '\n'; i++)
		line[i] = ch;

	if (ch == '\n') {
		line[i++] = '\n';
		line[i] = '\0';
	} else {
		line[i] = '\n';
		line[i + 1] = '\0';
	}

	return i;
}
