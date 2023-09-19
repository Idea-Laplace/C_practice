#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define WEEK 7
#define LEN (int) sizeof(weekend) / sizeof(weekend[0])

int main(void) {
	bool weekend[WEEK] = {true,[6] = true}; // Designated initializer used (C99 standard)
	for (int i = 0; i < LEN; ++i)
		printf("%d ", weekend[i]);
	printf("\n");

	system("pause");
	return 0;
}
