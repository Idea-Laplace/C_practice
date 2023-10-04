#include <stdio.h>
#include <stdlib.h>

int *create_array(int len, int initial_value) {
	int *arr = (int *) malloc(len * sizeof(int));
	if (arr == NULL) {
		printf("Error: malloc in *create_array failed.\n");
		return NULL;
	}

	for (int i = 0; i < len; i++)
		*(arr + i) = initial_value;

	return arr;
}


