// Quick sort algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// Macro
#define SIZE(array) (int) (sizeof array / sizeof array[0])

// Prototypes
int create_random_number(int max_value);
void quick_sort(int a[], int low, int high);

// Main
int main(void) {
	int array[20];
	int max;

	for (;;) {
		printf("Enter a max number to be in an array: ");
		scanf("%d", &max);
		getchar();    // Flush '\n'


		// Print array before sorted.
		srand((unsigned) time(NULL));
		printf("Initialized\n");
		printf("{ ");
		for (int i = 0; i < SIZE(array); ++i) {
			array[i] = create_random_number(max);
			printf("%d ", array[i]);
		}
		printf("}\n\n");

		quick_sort(array, 0, SIZE(array) - 1);

		// Print array after sorted.
		printf("Sorted\n");
		printf("{ ");
		for (int i = 0; i < SIZE(array); ++i) {
			printf("%d ", array[i]);
		}
		printf("}\n");

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			getchar();
			
			switch (reply) {
				case 'Y': printf("\n=============================\n"); break;
				case 'N': printf("Program terminated.\n"); goto end;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	end:
	system("pause");
	return 0;
}


int create_random_number(int max_value) {
	return rand() % max_value;
}


void quick_sort(int a[], int low, int high) {
	int temp = a[low];
	int high_arrow = high;
	int low_arrow = low;
	int middle;

	if (low >= high)
		return;

	while (low_arrow < high_arrow) {
		while (a[high_arrow] >= temp && high_arrow > low_arrow)
			--high_arrow;
		a[low_arrow] = a[high_arrow];
		
		while (a[low_arrow] <= temp && high_arrow > low_arrow)
			++low_arrow;
		a[high_arrow] = a[low_arrow];
	}
	a[high_arrow] = temp; // We can use low_arrow instead of high_arrow
	middle = high_arrow;

	quick_sort(a, middle + 1, high);
	quick_sort(a, low, middle - 1);
}



