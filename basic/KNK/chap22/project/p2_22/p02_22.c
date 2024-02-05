/* Write a program that converts all letters in a file to upper case.
   (Characters other than letters shouldn't be changed.) The program
   should obtain the file name from the commmand line and write its
   output to stdout. */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: $./p02_22 {filename}\n");
		exit(EXIT_FAILURE);
	}

	FILE *fp;

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File %s cannot be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	int ch;
	while ((ch = fgetc(fp)) != EOF) {
		if (ferror(fp)) {
			printf("Error in reading.\n");
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		if (feof(fp)) {
			printf("Early EOF error.\n");
			fclose(fp);
			exit(EXIT_FAILURE);
		}

		fputc(toupper(ch), stdout);
	}

	fclose(fp);
	return 0;
}
