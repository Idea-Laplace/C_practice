#include <stdio.h>

#define LINE 8

int line_length(const char *filename, int n);


int main(int argc, char **argv) {
	int n;

	n = line_length(argv[1], LINE);
	printf("line %d: %d characters\n", LINE, n);
	return 0;
}

int line_length(const char *filename, int n) {
	FILE *fp;
	int ch;
	int length = 0;

	if (n <= 0) {
		printf("Line number should be positive integers.\n");
		return 0;
	}

	if ((fp = fopen(filename, "r")) == NULL) {
		printf("File %s cannot be opened.\n", filename);
		return 0;
	}

	for (int i  = 1; i < n; i++)
		while ((ch = fgetc(fp)) != '\n') {
			if (ch == EOF) {
				printf("Error detected while reading.\n");
				fclose(fp);
				return 0;
			}
		}

	while ((ch = fgetc(fp)) != '\n') {
		if (ch == EOF) {
			printf("Error detected while reading.\n");
			fclose(fp);
			return 0;
		}

		length++;
	}

	fclose(fp);

	return length;
}








