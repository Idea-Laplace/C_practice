#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10



int inner_product(int a[], int b[], int n);

int main(void) {
	for (;;) {
		int arr1[SIZE], arr2[SIZE];
		srand((unsigned) time(NULL));
		for (int i = 0; i < SIZE; ++i) {
			arr1[i] = rand() % 30;
			arr2[i] = rand() % 30;
		}

		printf("arr1: ");
		for (int i = 0; i < SIZE; ++i)
			printf("%2d ", arr1[i]);
		printf("\n");

		printf("arr2: ");
		for (int i = 0; i < SIZE; ++i)
			printf("%2d ", arr2[i]);
		printf("\n");

		printf("Inner product: %d\n", inner_product(arr1, arr2, SIZE)); 
		
		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n==============================\n"); break;
				case 'n': printf("Program terminated.\n"); goto end;
				default : printf("Enter y or n.\n"); break;
			}
		} while (reply != 'y');
	}
	end:
	system("pause");
	return 0;
}

int inner_product(int a[], int b[], int n) {
	int scalar = 0;
	for (int i = 0; i < SIZE; ++i)
		scalar += a[i] * b[i];

	return scalar;
}
