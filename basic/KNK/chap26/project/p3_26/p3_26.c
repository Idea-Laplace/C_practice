/*
   Wrtie a program that uses the clock function to measure how long
   it takes qsort to sort an array of 1000 integers that are orignally
   in reverse order, Run the program for arrays of 10000 and 100000
   integers as well.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10000

int compare(const void *x, const void *y) {
	return *((int *) x) - *((int *) y);
}

int main(void) {
	clock_t start, end;
	int reverse[LEN];
	int rand_arr[LEN];

	srand((unsigned) time(NULL));

	for (int i = 0; i < LEN; i++) {
		reverse[i] = LEN - i;
		rand_arr[i] = rand() % LEN;
	}

	start = clock();
	qsort(reverse, sizeof(reverse) / sizeof(*reverse), sizeof(*reverse), &compare);
	end = clock();

	printf("Sec consumed sorting reverse order array by quicksort algorithm: %ld\n", (end - start)/CLOCKS_PER_SEC);

	start = clock();
	qsort(rand_arr, sizeof(rand_arr) / sizeof(*rand_arr), sizeof(*rand_arr), &compare);
	end = clock();

	printf("Sec consumed sorting random order array by quicksort algorithm: %ld\n", (end - start)/CLOCKS_PER_SEC);

	return 0;
}
   
