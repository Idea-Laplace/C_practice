#include <stdio.h>
#include <stdlib.h>
#define LEN (int) sizeof(fibonacci) / sizeof(fibonacci[0])
#define TERM 40


int main (void) {
	int fibonacci[TERM];
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i < LEN; ++i) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	for (int i = 0; i < LEN; ++i)
		printf("%d ", fibonacci[i]);

	printf("\n");
	system("pause");
	return 0;
}
