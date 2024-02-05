// Extend the canopen.c program of section 22.2 so that
// the user may put any number of file names on the command line.


// The program should print a separate 'can be' or 'can't be' opened
// message for each file. Have the program terminate with status EXIT_FAILURE
// if one or more of the files can't be opened.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *fp;
	bool canopen = true;
	

	if (argc <= 1) {
		printf("Usage: $canopen {filename1} [{filename2} ...]\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			printf("%s can't be opened\n", argv[i]);
			canopen = false;
		}

		else {
			printf("%s can be opened.\n", argv[i]);
			fclose(fp);
		}
	}

	if (canopen)
		return 0;
	else
		exit(EXIT_FAILURE);
}
