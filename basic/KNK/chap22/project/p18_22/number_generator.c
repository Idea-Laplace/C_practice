#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITER 100

int main(int argc, char **argv) {
	FILE *fp;
	int iteration;

	if (argc != 2) {
		fprintf(stderr, "Error: Usage> $number_generater {filename}\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "w");
	if (fp == NULL) {
		fprintf(stderr, "File %s can't be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	srand((unsigned) time(NULL));
	iteration = rand() % MAX_ITER;

	for (int i = 0; i < iteration; i++)
		fprintf(fp, "%d ", rand() % MAX_ITER);

	fclose(fp);
	return 0;
}

