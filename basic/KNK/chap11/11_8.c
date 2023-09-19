// KNK 2nd edition, chap11, problem8 p.256
/*******************************************************
* When passed an array 'a' of length n, the function   *
* will return a pointer to the array's largest element.*
* *****************************************************/

#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Macro
#define LENGTH(arr) ((int) sizeof(arr) / sizeof(arr[0])) // Length of a given array argument

// Prototype(s)
int *find_largest(int array[], int n);

// Main
int main(void){
	bool loop = true;
	while(loop){
		int length, *answer;
		printf("Enter a length of an array: ");
		scanf("%d", &length);
		getchar();    // Truncate '\n'
		int array[length];

		for(int i = 0; i < length; ++i){
			printf("Insert an interger on array index %d: ", i);
			scanf("%d", &array[i]);
			getchar();    // Truncate '\n'
		}

		answer = find_largest(array, LENGTH(array));
		printf("The pointer of the largest value of given array: %p\n", answer);
		printf("At %p, value %d is stored.\n", answer, *answer);

		// Loop decision
		char reply;
		do{
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch(reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first character.\n"); break;
			}
		}while(reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}


// Function(s)
int *find_largest(int array[], int n){
	int *largest_address = array;
	for (int i = 0; i < n; ++i){
		if (*largest_address < array[i])
			largest_address = &array[i];
	}
	return largest_address;
}

