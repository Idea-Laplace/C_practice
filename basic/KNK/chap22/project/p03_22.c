/* Write a program named fcat that 'concatenates' any number of files by writing
   them to standard output, one after the other, with no break between files.
   For example, the following command will display the files f1.c f2.c, and f3.c
   on the screen.
   fcat f1.c f2.c f3.c

   fcat should issue an error message if any files con't be opened.
	Hint: Since it has no more than one file open at a time, fcat
	needs only a single file pointer variable. Once it's finished
	with a file, fact can use the sanme variable when it opens the
	next file. */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	FILE *fp;
	int ch;

	for (int i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "File %s cannot be opened.\n", argv[i]);
			continue;
		}

		while ((ch = fgetc(fp)) != EOF)
			putchar(ch);
		fclose(fp);
	}

	return 0;
}

