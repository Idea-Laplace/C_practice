#ifndef QUICKSORT
#define QUICKSORT

// The quicksort function sorts a given int array by quicksort algorithm.
// The parameter int *arr accept int array variable and len_arr is the length
// of the given int array.
void quicksort(int *arr, int len_arr);

// split function is a single process for quicksort.
// The quicksort function will call split function recursively.
// The split function returns pointer on which low and high meets.
int *split(int *low, int *high);

#endif
