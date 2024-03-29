#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE 60

char line[MAX_LINE + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void) {
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word) {
	if (num_words > 0) {
		// A space should be inserted before
		// putting a new word following last word.
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}

	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void) {
	return MAX_LINE - line_len;
}

void write_line(FILE *fp) {
	int extra_spaces = MAX_LINE - line_len;
	int spaces_to_insert;
	for (int i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			fputc(line[i], fp);
		else {
			spaces_to_insert = extra_spaces / (num_words - 1);
			// 1 is for the basic space
			for (int j = 0; j < spaces_to_insert + 1; j++)
				fputc(' ', fp);
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	fputc('\n', fp);
}

void flush_line(FILE *fp) {
	if (line_len > 0)
		fputs(line, fp);
}


