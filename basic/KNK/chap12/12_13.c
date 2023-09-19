/************************************************
 * Initialize an identity matrix                *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro
# define SIZE 10

// External Variable(s)

// Prototype(s)
void identity_init(int arr[][SIZE]);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		int matrix[SIZE][SIZE];
		identity_init(matrix);
		for (int *p = &matrix[0][0]; p < &matrix[0][0] + SIZE * SIZE; ++p){
			if (((int) (p - &matrix[0][0])) % SIZE == 0){
				printf("\n");
			}
			printf("%d, ", *p);
		}
		printf("\n");
		

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
void identity_init(int arr[][SIZE]){
	for (int *p = &arr[0][0]; p < &arr[0][0] + SIZE*SIZE; ++p){
		int diagonal = ((int) (p - &arr[0][0]) % (SIZE + 1));
		if (diagonal == 0)
			*p = 1;
		else
			*p = 0;
	}
}
