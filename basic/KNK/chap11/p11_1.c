// KNK 2nd edition, chap11, project 1 p.256
/**********************************************
 * Modify Programming Projcet 7 from chapter2 *
 * so that it includes the following function:*
 **********************************************/
#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Macro

// Prototype(s)
void pay_amount(int dollars, int *twenties, int *tens,\
				int *fives, int *ones);


// Main
int main(void){
	bool loop = true;
	while(loop){
		// Input
		int dollars, twenties, tens, fives, ones;
		printf("Enter a value of dollars: ");
		scanf("%d", &dollars);
		while(getchar() != '\n');

		// Output
		pay_amount(dollars, &twenties, &tens, &fives, &ones);
		printf("Twenties: %d, Tens: %d, Fives: %d, Ones: %d\n", twenties, tens, fives, ones);
		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch(reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("Program terminated.\n");
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
void pay_amount(int dollars, int *twenties, int *tens,\
				int *fives, int *ones){
	*twenties = dollars / 20;
	dollars = dollars - 20*(dollars / 20);

	*tens = dollars / 10;
	dollars = dollars - 10*(dollars / 10);

	*fives = dollars / 5;
	dollars = dollars - 5*(dollars / 5);
	*ones = dollars;
}

