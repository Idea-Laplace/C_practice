#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Macro

// Prototype(s)
void reduce(int numerator, int denominator,\
			int *reduced_numerator, int *reduced_denominator);


// Main
int main(void){
	bool loop = true;
	while(loop){
		// Variables
		int numerator, denominator;
		int reduced_numerator, reduced_denominator;

		// Input
		printf("Enter a value of fraction in the form of m/n: ");
		scanf("%d /%d", &numerator, &denominator);
		while (getchar() != '\n');

		// Output
		reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);
		printf("The reduced fraction of %d/%d is %d/%d.\n", numerator, denominator,\
				reduced_numerator, reduced_denominator);

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
void reduce(int numerator, int denominator,\
			int *reduced_numerator, int *reduced_denominator){
	int gcd;
	if (denominator == 0){
		printf("A denominator must be nonzero, the default value 1 should be shown.\n");
		*reduced_numerator = 1;
		*reduced_denominator = 1;
	}
	else {
		int num1 = numerator;
		int num2 = denominator;
		int temp;
		while (num2 != 0){
			temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}
		gcd = temp > 0 ? temp : -temp;
	}

	*reduced_numerator = numerator / gcd;
	*reduced_denominator = denominator / gcd;
}

