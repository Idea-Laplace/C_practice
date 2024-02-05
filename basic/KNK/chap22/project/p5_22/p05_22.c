/* The xor. cprogram of Section 20.1 refuses to encrypt bytes that -
   in original or encrypted form - are control characters. We can now
   remove this restriction. Modify the program so that the names of the
   input and output files are command line arguments. Open both files in
   binary mode, and remove the test that checks whether the original and
   encrypted characters are printing characters. */

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char **argv) {
	FILE *fp;
	int ch;

	if (argc < 2) {
		fprintf(stderr, "Usage: $./p05_22 {filename1} [{filename2} ...]\n");
		exit(EXIT_FAILURE);
	}


	for (int i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "rb+")) == NULL) {
			fprintf(stderr, "File %s cannot be opened.\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		while ((ch = fgetc(fp)) != EOF) {
			ch ^= KEY;
			fseek(fp, -1, SEEK_CUR);
			fputc(ch, fp);
			fseek(fp, 0, SEEK_CUR);
		}

		fclose(fp);
	}

	return 0;
}

