#include <stdio.h>
#include <stdlib.h>
#define SIZE (int) sizeof(a) / sizeof(a[0])


int main(void) {
	for (;;) {
		int n;
		printf("Enter the size of array a: ");
		scanf("%d", &n);
		if (n <= 0)
			break;

		int a[n];
		printf("Enter %d numbers (with spacebar separation): ", n);
		for (int i = 0; i < SIZE; ++i)
			scanf("%d", &a[i]);

		printf("In reverse order: ");
		for (int i = SIZE - 1; i >= 0; --i)
			printf("%d ", a[i]);
		printf("\n");
	}

	printf("Program terminated.\n");
	system("pause");
	return 0;
}
