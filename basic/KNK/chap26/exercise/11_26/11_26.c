/*
   Although the bsearch function is normally used with a sorted array,
   it will sometimes work correctly with an array that is only partially
   sorted. What condition must an array satisfy to guarantee that bsearch
   works properly for a particular key?

	Hint: The answer appears in the C standard.
*/

#include <stdlib.h>

// The following paragraph is from stdlib.h.

/*
Do a binary search for KEY in BASE, which consists of NMEMB elements
of SIZE bytes each, using COMPAR to perform the comparisons.  

extern void *bsearch (const void *__key, const void *__base,
		      size_t __nmemb, size_t __size, __compar_fn_t __compar)

*/


/*
   Part of a quicksort algorithm includes that with a given number,
   any number smaller than the number is put to left, while larger number
   is put to right, this also can be a point for bsearch.

   As long as the target key is on a position where on its left-hand side
   are elements smaller than the key, while on its right-hand side are elements
   that are larger than the key, it would be properly searched by bsearch.

   This implies that if you want just a specific key, you even don't need to
   sort entire array, just spliting number group(which is a part of qsort algorithm)
   is sufficient to use bsearch.
*/


#include <stdio.h>

int compare(const void *x, const void *y) {
	return *((int *)x) - *((int *) y);
}

int main(void) {
	// Every number smaller than key(7) is on the left of key.
	// While every number bigger than key is on the right side of 7.
	int arr[] = {3, 4, 1, 5, 2, 7, 10, 9, 15, 22, 11, 13, 17, 15};
	int key = 7;

	int *p;

	p = (int *)bsearch(&key, arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), &compare);

	printf("key 7 is in %p\n", p);
	printf("index: %ld\n", p - arr);
	printf("value arr[%ld]: %d\n", p - arr, arr[(int)(p - arr)]);
	return 0;
}

