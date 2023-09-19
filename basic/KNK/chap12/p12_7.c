/************************************************
 * p12_7
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Macro
#define LENGTH 15

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
void max_min(int a[], int n, int *max, int *min);
void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

// Main
int main(void){
	bool loop = true;
	int max, min;
	while (loop){
		// Array initializtion
		srand((unsigned) time(NULL));
		int numbers[LENGTH];
		for (int *p = numbers; (p - numbers) < LENGTH; ++p)
			*p = rand() % 100;

		// Print the random given array
		printf("A given array of integers: {");
		for (int *p = numbers; (p - numbers) < LENGTH; ++p)
			printf("%d, ", *p);
		printf("\b\b}\n");

		// Quicksort
		quicksort(numbers, numbers, numbers + LENGTH - 1);
		printf("After quicksorted: {");
		for (int *p = numbers; (p - numbers) < LENGTH; ++p)
			printf("%d, ", *p);
		printf("\b\b}\n");

		// Max, Min
		max_min(numbers, LENGTH, &max, &min);
		printf("Min: %2d, Max: %2d\n", min, max);

		// Loop decision
		loop_decision(&loop);
	}
	system("pause");
	return 0;
}

// Function(s)
void loop_decision(bool *loop){
	char reply;
	do {
		printf("Loop this program?(y/n): ");
		reply = toupper(getchar());
		while (getchar() != '\n');
		switch (reply){
			case 'Y': printf("\n===================================\n"); break;
			case 'N': printf("\n===================================\n");
					  printf("Program terminated.\n");
					  *loop = false;
					  break;
			default : printf("Type y[Y] or n[N] on the first input.\n"); break;
		}
	} while (reply != 'Y' && reply != 'N');
}

void max_min(int a[], int n, int *max, int *min){
	*min = *max = *a;
	for (int *p = a; (p - a) < n; ++p){
		int logic = (int) (*p > *min) + (*p > *max);
		switch (logic){
			case 0: *min = *p; break;
			case 1: break;
			case 2: *max = *p; break;
			default: break;
		}
	}
}

void quicksort(int a[], int *low, int *high){
	if (low >= high)
		return;
	int *middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int *split(int a[], int *low, int *high){
	int poped_element = *low;
	for (;;){
		while (low < high && *high >= poped_element)
			--high;
		if (low == high)
			break;
		*low++ = *high;

		while (low < high && *low <= poped_element)
			++low;
		if (low == high)
			break;
		*high-- = *low;
	}
	*low = poped_element;
	return low;
}


