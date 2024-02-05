/*
	(a) Write a program that counts the number of characters in a text file.
	(b) Write a program that counts the number of words in a text file.
	(A 'word' is any sequence of no  white characters.)
	(c) Write a program that counts the number of lines in a text file.

	Have each program obtain the file name from the command line.
*/


#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int count_char(FILE *fp);
int count_word(FILE *fp);
int count_line(FILE *fp);

int main(int argc, char **argv) {
	FILE *fp;
	int ch;

	if (argc < 2) {
		fprintf(stderr, "Usage: $./p04_22 {filename}\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "File %s cannot be opened.\n", argv[i]);
			continue;
		}

		printf("Information\n");
		printf("Number of characters: %d\n", count_char(fp));
		rewind(fp);
		printf("Number of words: %d\n", count_word(fp));
		rewind(fp);
		printf("Number of lines: %d\n\n", count_line(fp));

		fclose(fp);
	}

	return 0;
}



int count_char(FILE *fp) {
	int count = 0;
	while (fgetc(fp) != EOF)
		count++;

	return count;
}

int count_word(FILE *fp) {
	int count = 0;
	int ch;
	bool in_word = false;

	while ((ch = fgetc(fp)) != EOF) {
		if (isspace(ch)) {
			in_word = false;
		}

		else if (!in_word) {
			in_word = true;
			count++;
		}
	}
	return count;
}

int count_line(FILE *fp) {
	int count = 0;
	int ch;

	while ((ch = fgetc(fp)) != EOF)
		if (ch == '\n')
			count++;
	return count;
}
