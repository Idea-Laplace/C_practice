#include <stdio.h>

int find_int(const char *filename) {
	FILE *fp = fopen(filename, "r");
	int n;

	if (fp == NULL)
		return -1;

	while (fscanf(fp, "%d", &n) != 1) {
		if (ferror(fp)) {
			fclose(fp);
			fprintf(stderr, "Read error.\n");
			return -2;
		}

		if (feof(fp)) {
			fclose(fp);
			fprintf(stderr, "EOF error.\n");
			return -3;
		}
		fscanf(fp, "%*[^\n]");
	}
	fclose(fp);
	return n;
}
