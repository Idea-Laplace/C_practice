#include <stddef.h>
#include "my_qsort.h"

void my_qsort(void *base, size_t nmemb, size_t size,\
			int (*compare)(const void *, const void *)) {

	if (nmemb <= 1U) return;

	void *left = base;
	void *right = base + (nmemb - 1) * size;
	void *split = left;
	void *middle;

	// Split Process=========================================
	for (;;) {
		while (left < right && compare(split, right) >= 0)
			right -= size;
		if (left >= right) break;
		*left = *right;
		left += size;

		while (left < right && compare(left, split) >= 0)
			left += size;
		if (left >= right) break;
		*right = *left;
		right += size;
	}

	*right = *split;
	// ======================================================

	middle = split;
	

	size_t recur_nmemb1 = (size_t) (split - base) / size;
	size_t recur_nmemb2 = (size_t) (base + size * (nmemb - 1) - split) / size;
	my_qsort(base, recur_nmemb1 , size, &compare);
	my_qsort(split + size, recur_nmemb2, size, &compare);
}

