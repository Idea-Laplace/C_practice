/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O

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

