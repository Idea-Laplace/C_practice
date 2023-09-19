#include <stdio.h>
#include <stdlib.h> // system()
#include <ctype.h>  // toupper()
#include <stdbool.h> // true/false
// Macro

// Prototype

// Main
int main(void){
	bool loop = true;
	while(loop){
		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch (reply) {
				case 'Y': printf("\n=========================\n"); break;
				case 'N': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y[Y] or n[N].\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}
