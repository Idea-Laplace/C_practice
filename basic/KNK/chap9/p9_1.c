#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int selection_sort(int arr[], int n);
int main(void) {
	for (;;) {
		int arr[SIZE];

		srand((unsigned) time(NULL));
		printf("Array initialized: { ");
		for (int i = 0; i < SIZE; ++i) {
			arr[i] = rand() % 100;
			printf("%d ", arr[i]);
		}
		printf("}\n");

		selection_sort(arr, SIZE);
		printf("Array sorted: { ");
		for (int i = 0; i < SIZE; ++i)
			printf("%d ", arr[i]);
		printf("}\n");

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


int selection_sort(int arr[], int n) {
	int max = arr[0], temp, index = 0;

	if (n <= 0) {
		printf("Error: Length of an array must be positive.\n");
		return -1;
	}

	if (n == 1) {
		printf("Sorting process completed.\n");
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}

	temp = arr[n - 1];
	arr[n - 1] = max;
	arr[index] = temp;

	selection_sort(arr, n - 1);
}
