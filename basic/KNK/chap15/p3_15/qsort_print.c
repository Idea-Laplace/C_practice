#include <stdio.h>
#include "quicksort.h"

#define MAX_LEN 20
#define DEFAULT_LEN 5


int main(void) {
	int length;
	
	printf("Enter a length of array less than or equal to %d: ", MAX_LEN);
	scanf("%d", &length);
	if (length > MAX_LEN) {
		printf("Input is Larger than %d, array length is given to %d.\n",\
				MAX_LEN, MAX_LEN);
		length = MAX_LEN;
	}
	while (getchar() != '\n');

	if (length <= 0) {
		printf("Input is invalid, array length is given to %d.\n", DEFAULT_LEN);
		length = DEFAULT_LEN;
	}

	int arr[length];
	printf("Input %d integer elements for the given array: ", length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &arr[i]);
	}
	while (getchar() != '\n');

	printf("Your array :\n{");
	for (int i = 0; i < length; i++)
		printf("%d, ", arr[i]);
	printf("\b\b}\n");

	quicksort(arr, length);

	printf("After sorted:\n{");
	for (int i = 0; i < length; i++)
		printf("%d, ", arr[i]);
	printf("\b\b}\n");

	return 0;
}
