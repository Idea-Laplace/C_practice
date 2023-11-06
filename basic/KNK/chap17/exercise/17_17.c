#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./qsort/qsort.h"

#define LEN 20
#define INDEX 10


void part_sort(void (*f)(int *, int), int index, int *arr);

int main(void) {
	int arr[LEN];
	int index = INDEX;
	srand((unsigned) time(NULL));

	for (int i = 0; i < LEN; i++)
		arr[i] = rand() % 100;

	printf("{");
	for (int i = 0; i < LEN; i++) {
		printf("%2d", arr[i]);
		i == LEN - 1 ? printf("}\n") : printf(", ");
	}
	part_sort(quick_sort, index, arr);
	printf("{");
	for (int i = 0; i < LEN; i++) {
		printf("%2d", arr[i]);
		i == LEN - 1 ? printf("}\n") : printf(", ");
	}

	return 0;
}

void part_sort(void (*f)(int *, int), int index, int *arr) {
	(*f)(arr + index, LEN - index);
}

