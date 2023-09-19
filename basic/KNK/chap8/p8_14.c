#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMUM_LENGTH 500


int main (void) {
	bool loop = true;

	while (loop) {
		char letter;
		char word[MAXIMUM_LENGTH] = {' '}; // word[0] = ' ';  for algorithm purpose
		int index, word_start, word_end;
		
		// Input
		printf("Enter a sentence: ");
		for (index = 1; index < MAXIMUM_LENGTH; ++index) {
			if ((letter = getchar()) == '.' || letter == '?' || letter == '!')
				break;
			word[index] = letter;
		}
		getchar(); // Litter '\n'.

		// word[0] = ' ' is exploited in following part.
		word_end = index - 1;   // When the previous loop ends, index increases by 1.
		printf("Reversal of sentence:");

		while (word_end > 0) {
			for (word_start = word_end; word[word_start] != ' '; --word_start);
			for (int i = 0; i + word_start <= word_end; ++i)
				putchar(word[word_start + i]);
			word_end = word_start - 1;
		}
		printf("%c\n", letter);

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
