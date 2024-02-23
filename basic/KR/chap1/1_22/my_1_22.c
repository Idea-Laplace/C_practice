/* Write a program to 'fold' long input lines into 2 or more
 * shorter lines after the last non-blank character that occurs
 * before the nth column of input. Make sure your program does
 * something intelligent with very long lines, and if there are
 * no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define LINEWIDTH 10
#define TABSTOP 4

int tabstop(char line[], int pos);
int find_blank(char line[], int pos);
int newpos(char line[], int pos);

int main(void) {
	int ch, pos;
	char line[LINEWIDTH + 1];

	pos = 0;
	while ((ch = getchar()) != EOF) {
		line[pos] = ch;
		if (ch == '\t') 
			pos = tabstop(line, pos);
		else if (ch == '\n') {
			line[pos + 1] = '\0';
			printf("%s", line);
			pos = 0;
		} else if (++pos >= LINEWIDTH) {
			pos = find_blank(line, pos);
			line[pos] = '\0';
			printf("%s\n", line);
			pos = newpos(line, pos);
		}
	}
	return 0;
}


int tabstop(char line[], int pos) {
	line[pos++] = ' ';

	for (; pos < LINEWIDTH && pos % TABSTOP != 0; ++pos)
		line[pos] = ' ';
	if (pos < LINEWIDTH)
		return pos;
	else {
		line[pos] = '\0';
		printf("%s\n", line);
		return 0;
	}
}
	
int find_blank(char line[], int pos) {
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if (pos == 0)
		return LINEWIDTH;
	else
		return pos;
}

int newpos(char line[], int pos) {
	int i, j;

	if (pos <= 0 || pos >= LINEWIDTH)
		return 0;
	else {
		i = 0;
		for (j = pos + 1; j < LINEWIDTH; ++j) {
			line[i] = line[j];
			++i;
		}
		return i;
	}
}
