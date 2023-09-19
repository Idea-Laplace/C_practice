/**********************************************************
 * KNK 2nd edition chapter 11, Programming Projects No.4  *
 * Modify projects 5 in chap 10                           *
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Macro
// External variable(s)

// Prototype(s)


// Main
int main(void){
	bool loop = true;
	while(loop){
		// Input
		// Output
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
		} while(reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}


// Function(s)

