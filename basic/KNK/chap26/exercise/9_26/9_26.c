// Write a function that returns a random double value d in the range 0.0 <= d <= 1.0.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_double(void);

int main(void) {
	double d;

	srand((unsigned) time(NULL));

	for (int i = 0; i < 20; i++) {
		d = rand_double();
		printf("%f ", d);
	}
	printf("\n");

	return 0;
}

double rand_double(void) {
	return (double)rand() / ((unsigned)RAND_MAX + 1);
}
