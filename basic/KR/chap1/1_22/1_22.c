/* Write a program to 'fold' long input lines into 2 or more
 * shorter lines after the last non-blank character that occurs
 * before the nth column of input. Make sure your program does
 * something intelligent with very long lines, and if there are
 * no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptab(int pos);
int find_blank(int pos);
int newpos(int pos);
void printl(int pos);

int main(void) {
	int ch, pos;
	pos = 0;
	while ((ch = getchar()) != EOF) {
		line[pos] = ch;
		if (ch == '\t') 
			pos = exptab(pos);
		else if (ch == '\n') {
			printl(pos);
			pos = 0;
		} else if (++pos >= MAXCOL) {
			pos = find_blank(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}
	return 0;
}

void printl(int pos) {
	for (int i = 0; i < pos; i++)
		putchar(line[i]);
	if (pos > 0)
		putchar('\n');
}


int exptab(int pos) {
	line[pos++] = ' ';

	for (; pos < MAXCOL && pos % TABINC != 0; ++pos)
		line[pos] = ' ';
	if (pos < MAXCOL)
		return pos;
	else {
		printl(pos);
		return pos;
	}
}
	
int find_blank(int pos) {
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if (pos == 0)
		return MAXCOL;
	else
		return pos + 1;
}

int newpos(int pos) {
	int i, j;

	if (pos <= 0 || pos >= MAXCOL)
		return 0;
	else {
		i = 0;
		for (j = pos; i < MAXCOL; ++j) {
			line[i] = line[j];
			++i;
		}
		return i;
	}
}
