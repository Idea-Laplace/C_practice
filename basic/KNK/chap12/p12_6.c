/************************************************
 * p12_6, Quicksort by pointer                  *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h> // system(), srand(), rand()
#include <stdbool.h>  // type bool
#include <ctype.h>  // toupper()
#include <time.h> // time()

// Macro
#define LENGTH 15

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

// Main
int main(void){
	bool loop = true;
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


