/************************************************
 * p12_5, Modify p8_14.                         *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro
#define MAXIMUM_LENGTH 500

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);

// Main
int main(void){
	bool loop = true;
	while (loop){
		char last_letter;
		char sentence[MAXIMUM_LENGTH] = {' '}; // sentence[0] = ' ';  for algorithm purpose
		char *index, *word_start, *word_end;
		
		// Input
		printf("Enter a sentence: ");
		for (index = sentence + 1; (index - sentence) < MAXIMUM_LENGTH; ++index) {
			if ((last_letter = getchar()) == '.' || last_letter == '?' || last_letter == '!')
				break;
			*index = last_letter;
		}
		while(getchar() != '\n'); // Litter '\n'.

		// sentence[0] = ' ' is exploited in following part.
		word_end = index - 1;   // When the previous loop ends, index increases by 1.
		printf("Reversal of sentence:");

		while (word_end > sentence) {
			for (word_start = word_end; *word_start != ' '; --word_start);
			for (char *ch = word_start; ch <= word_end; ++ch)
				putchar(*ch);
			word_end = word_start - 1;
		}
		printf("%c\n", last_letter);

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

