#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Prototype(s)
void swap(int *num1, int *num2);

int main(void){
	bool loop = true;

	while(loop){
		int i, j;

		printf("Enter an interger on the variable i: ");
		scanf("%d", &i);
		while(getchar() != '\n');

		printf("Enter an interger on the variable j: ");
		scanf("%d", &j);
		while(getchar() != '\n');

		printf("You put a value on i: %d\n", i);
		printf("You put a value on j: %d\n", j);
		printf("\nSwap function activated.\n");
		swap(&i, &j);
		printf("Now in i: %d\n", i);
		printf("Now in j: %d\n", j);
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
void swap(int *num1, int *num2){
	int temp;
	temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}
