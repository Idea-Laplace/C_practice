#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void store(FILE *);

int main(int argc, char **argv) {
	FILE *fp;
	char filename[20 + 1];

	strcpy(filename, argv[1]);

	if (strcmp(filename, "stdin") != 0) {
		fp = fopen(filename, "r");
		if (fp == NULL) {
			fprintf(stderr, "File not created.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		fp = stdin;

	store(fp);

	return 0;
}

void store(FILE *fp) {
	char test_str[100 + 1] = {'\0'};
	int num;

	while (fread(test_str, 1, 100, fp) > 0)
		printf("%s\n", test_str);
	return;
}
