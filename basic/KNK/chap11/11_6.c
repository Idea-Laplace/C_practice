// KNK 2nd edition, chap11, problem6 p.255
#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Macro
#define LENGTH(array) ((int) sizeof(array) / sizeof(array[0]))

// Prototype(s)
int find_two_largest(int a[], int length, int *largest, int *second_largest);


// Main
int main(void){
	bool loop = true;
	while(loop){
		int length, largest, second_largest;
		printf("Enter a length of an array: ");
		scanf("%d", &length);
		getchar();    // Truncate '\n'
		int array[length];

		for(int i = 0; i < length; ++i){
			printf("Insert an interger on array index %d: ", i);
			scanf("%d", &array[i]);
			getchar();    // Truncate '\n'
		}

		find_two_largest(array, LENGTH(array), &largest, &second_largest);
		printf("Largest: %d,\tSecond_Largest: %d\n", largest, second_largest);

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
int find_two_largest(int a[], int length, int *largest, int *second_largest){
	int temp1, temp2;
	if (length < 2){
		printf("Index out of range(too small), unexpected result may rise.\n");
		return -1;
	}
	a[1] > a[0] ? (temp1 = a[1], temp2 = a[0]) : (temp1 = a[0], temp2 = a[1]);
	for(int i = 2; i < length; ++i){
		int logic_sum = (a[i] > temp2) + (a[i] > temp1);
		switch (logic_sum){
			case 0: break;
			case 1: temp2 = a[i]; break;
			case 2: temp2 = temp1; temp1 = a[i]; break;
			default: break;
		}
	}
	*largest = temp1;
	*second_largest = temp2;
	return 0;
}



