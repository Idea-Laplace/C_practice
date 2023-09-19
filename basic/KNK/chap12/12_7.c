/************************************************
 * KNK 2nd edition chap12 problem 7             *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Macro

// External Variable(s)

// Prototype(s)
bool search(const int *array, int length_of_array, int key);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		int length;
		int key;
		printf("Enter a length of array: ");
		scanf("%d", &length);
		while(getchar() != '\n');

		srand(time(NULL));
		int array[length];
		printf("The array is given by:\n");
		printf("{");
		for (int *p = array; p < array + length; ++p){
			*p = rand() % length;
			printf("%d, ", *p);
		}
		printf("\b\b}\n");

		printf("Enter a key to search: ");
		scanf("%d", &key);
		while (getchar() != '\n');


		printf("The key is%sin the given array.\n", search(array, length, key) ? " " : " not ");


		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while (getchar() != '\n');
			switch (reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("Program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first input.\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}

// Function(s)
bool search(const int *array, int length_of_array, int key){
	bool match_key = false;
	for (int i = 0; i < length_of_array; ++i){
		if (key == *(array + i)){
			match_key = true;
		}
	}
	return match_key;
}
