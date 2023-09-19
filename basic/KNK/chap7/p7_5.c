#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int main (void) {
	bool loop = true;

	while (loop) {
		int scrabble = 0;
		char word;

		printf("Enter a word: ");
		while ((word = getchar()) != '\n') {
			switch (toupper(word)) { 
				case 'A': case 'E': case 'I': case 'L': case 'N':
				case 'O': case 'R': case 'S': case 'T': case 'U':
					scrabble += 1; break;
				case 'D': case 'G':
					scrabble += 2; break;
				case 'B': case 'C': case 'P': case 'M':
					scrabble += 3; break;
				case 'F': case 'H': case 'V': case 'W': case 'Y':
					scrabble += 4; break;
				case 'K':
					scrabble += 5; break;
				case 'J': case 'X':
					scrabble += 8; break;
				case 'Q': case 'Z':
					scrabble += 10; break;
				default : break;
			}
		}
		printf("Scrabble value: %d\n", scrabble);


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
