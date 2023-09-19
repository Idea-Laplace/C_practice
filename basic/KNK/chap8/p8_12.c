#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHABET 26
#define SIZE (int) (sizeof(scrabble) / sizeof(scrabble[0])

int main (void) {
	bool loop = true;

	while (loop) {
		const char scrabble[ALPHABET] = {1, 3, 3, 2, 1, 4, 2,\
										4, 1, 8, 5, 1, 3, 1,\
										1, 3, 10, 1, 1, 1, 1,\
										4, 4, 8, 4, 10};
		char word;
		int score = 0;

		printf("Enter a word: ");
		while ((word = getchar()) != '\n') {
			word = toupper(word);
			score += scrabble[word - 'A'];
			}
		printf("Scrabble value: %d\n", score);


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
