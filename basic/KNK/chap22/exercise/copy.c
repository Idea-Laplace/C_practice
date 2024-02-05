/*
   The fcopy.c program has one minor flaw: it doesn't check for errors
   as it's writing to the destination file. Errors during writing are rare,
   but do occasionally occur (the disk might become full, for example).
   Show how to add the missing error chekc to the program, assuming that
   we want i to display a message and terminate immediately if an error occurs.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *source_fp, *dest_fp;
	int ch;

	if (argc != 3) {
		fprintf(stderr, "usage: linux> fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(source_fp)) != EOF) {
		// Check errors while copying.
		if (putc(ch, dest_fp) == EOF) {
			fprintf(stderr, "Error during writing; copy terminated\n");
			exit(EXIT_FAILURE);
		}
	}

	fclose(source_fp);
	fclose(dest_fp);

	return 0;
}

