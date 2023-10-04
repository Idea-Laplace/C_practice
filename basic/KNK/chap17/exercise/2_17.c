#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *duplicate(char *str) {
	char *p = malloc(strlen(str) + 1);

	if (p == NULL) {
		printf("Error: malloc failed in duplicate(str).\n");
		exit(EXIT_FAILURE);
	}

	strcpy(p, str);
	return p;
}

