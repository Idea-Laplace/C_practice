#include "quicksort.h"


void quicksort(int *arr, int len_arr) {
	int *low = arr, *high = arr + len_arr - 1;
	if (low >= high)
		return;
	int *middle = split(low, high);

	quicksort(low, (int) (middle - low));
	quicksort(middle + 1, (int) (high - middle));
}


int *split(int *low, int *high) {
	int store = *low;
	for (;;) {
		while (*high >= store && low < high)
			high--;
		if (low >= high)
			break;
		*low++ = *high;

		while (*low <= store && low < high)
			low++;
		if (low >= high)
			break;
		*high-- = *low;
	}
	*high = store;
	return high;
}






