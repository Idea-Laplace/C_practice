#include <stdlib.h>
#include <stdio.h>

void *my_malloc(size_t n) {
	void *p;
	if ((p = malloc(n)) == NULL) {
		printf("Error: cannot allocate n bytes.\n");
		exit(EXIT_FAILURE);
	}

	return p;
}
