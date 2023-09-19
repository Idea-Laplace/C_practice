#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void) {
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word) {
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}
	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void) {
	return MAX_LINE_LEN - line_len;
}

void write_line(void) {
	int extra_spaces = space_remaining();
	int store_spaces[MAX_LINE_LEN];
	int alternate, count_niche;
	int i;
	count_niche = num_words - 1;
	for (i = 0; count_niche > 0; i++) {
		store_spaces[i] = extra_spaces / count_niche;
		extra_spaces -= extra_spaces / count_niche;
		count_niche--;
	}
	alternate = store_spaces[0];
	store_spaces[0] = store_spaces[i - 1];
	store_spaces[i - 1] = alternate;

	for (i = 0; i < line_len; ++i) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			for (int j = 0; j < store_spaces[count_niche] + 1; ++j)
				putchar(' ');
			++count_niche;
		}
	}
	putchar('\n');
}

void flush_line(void) {
	if (line_len > 0)
		puts(line);
}



