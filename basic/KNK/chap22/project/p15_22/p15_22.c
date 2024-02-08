#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD 20

int main(int argc, char **argv) {
	char word[MAX_WORD + 1 + 1];
	int word_len;
	FILE *fp_in, *fp_out;

	if (argc != 3) {
		fprintf(stderr, "Usage: $./p15_22 {filename_in} {file_out}\n");
		exit(EXIT_FAILURE);
	}

	fp_in = fopen(argv[1], "r");
	fp_out = fopen(argv[2], "w");

	if (fp_in == NULL) {
		fprintf(stderr, "File %s cannot be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (fp_out == NULL) {
		fprintf(stderr, "File %s cannot be opened.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	clear_line();
	for (;;) {
		read_word(word, MAX_WORD + 1, fp_in);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line(fp_out);
			fclose(fp_in);
			fclose(fp_out);
			return 0;
		}

		if (word_len > MAX_WORD)
			word[MAX_WORD] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line(fp_out);
			clear_line();
		}
		add_word(word);
	}
}
