/*********************
 * Telephone mapping *
 * 2 = ABC  6 = MNO  *
 * 3 = DEF  7 = PQR  *
 * 4 = GHI  8 = STU  *
 * 5 = JKL  9 = WXYZ *
 * *******************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		char input;
		printf("Enter a phone number (in upper case): ");
		while ((input = getchar()) != '\n') {
			switch (input) {
				case 'A': case 'B': case 'C':
					printf("2"); break;
				case 'D': case 'E': case 'F':
					printf("3"); break;
				case 'G': case 'H': case 'I':
					printf("4"); break;
				case 'J': case 'K': case 'L':
					printf("5"); break;
				case 'M': case 'N': case 'O':
					printf("6"); break;
				case 'P': case 'R': case 'S':
					printf("7"); break;
				case 'T': case 'U': case 'V':
					printf("8"); break;
				case 'W': case 'X': case 'Y': case 'Z':
					printf("9"); break;
				default : printf("%c", input); break;
			}
		}
		printf("\n");
		input = getchar(); getchar(); // Enter 1
		printf("Test: %d(Ascii), %c(char)\n", input, input);
		
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
