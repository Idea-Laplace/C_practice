// Count characters in input; first version.

#include <stdio.h>

int main(void) {
	long nc = 0;

	while (getchar() != EOF) nc++;
	printf("Characters: %ld\n", nc);
	return 0;
}
