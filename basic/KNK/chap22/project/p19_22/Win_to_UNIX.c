#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *fp_win, *fp_unix;
	int ch;

	if (argc != 3) {
		fprintf(stderr, "Usage: $./Win_to_UNIX {window_file} {unix_file}\n");
		exit(EXIT_FAILURE);
	}

	if ((fp_win = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s file.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fp_unix = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s file.\n", argv[2]);
		fclose(fp_win);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp_win)) != EOF) {
		if (ch == '\r') continue;
		fputc(ch, fp_unix);
	}

	fclose(fp_win);
	fclose(fp_unix);

	return 0;
}

