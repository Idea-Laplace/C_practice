// In this program no operator takes precedence over any other operator.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		float pre, pos;
		char operator;
		
		printf("This program does not consider any precedence among operators, no parentheses are allowed.\n");
		printf("Enter an expression: ");
		scanf("%f", &pre);
		while ((operator = getchar()) != '\n') { 
			switch (operator) {
				case '+': scanf("%f", &pos); pre += pos; break;
				case '-': scanf("%f", &pos); pre -= pos; break;
				case '*': scanf("%f", &pos); pre *= pos; break;
				case '/': scanf("%f", &pos); pre /= pos; break;
				default : continue;
			}
		} 
			
		printf("Value of expression: %g\n", pre);


		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
