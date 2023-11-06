#include "qsort.h"

int *split(int *left, int *right) {
	int store = *left;

	while (left < right) {
		for (; *right >= store && left < right; right--)
			;
		*left = *right;

		for (; *left <= store && left < right; left++)
			;
		*right = *left;
	}

	*left = store;

	return left;
}


void quick_sort(int *arr, int len) {
	int *middle;
	if (len <= 1)
		return;

	middle = split(arr, arr + len - 1);

	quick_sort(arr, (int) (middle - arr));
	quick_sort(middle + 1, (int) ((arr + len) - middle - 1));
}

