/************************************************
 * Programming Project 12-2                     *
 * Write a program that reads a message, then   *
 * prints the revesal of the message.           *
 * Also, check palindrome.                      *
 * Ignore all that are not letters.             *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro
#define LENGTH 100

// External Variable(s)

// Prototype(s)
void reversal(char *sentence, int sentence_length);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Reversal
		char sentence[LENGTH] = {0};
		char *p = sentence;
		printf("Enter a sentence: ");
		while ((p - sentence) < LENGTH && (*p = getchar()) != '\n')
			++p;
		printf("Echo: ");
		for (char *q = sentence; q < p; ++q){
			printf("%c", *q);
		}
		printf("\n");

		while ((p - sentence) >= LENGTH && getchar() != '\n'); // Flush remain characters.

		// Panlindrome
		char letter_only[LENGTH] = {0};
		char *letter_count = letter_only;
		for (char *q = sentence; q < p; ++q){
			if (*q >= 'a' && *q <= 'z')
				*letter_count++ = toupper(*q);
			if (*q >= 'A' && *q <= 'Z')
				*letter_count++ = *q;
		}

		bool palindrome = true;
		for (char *pal = letter_only; pal < letter_count; ++pal){
			if (*pal != *(letter_count - 1 - (pal - letter_only))){
				palindrome = false;
				break;
			}
		}
		printf("Palindrome: %s\n", palindrome ? "TRUE" : "FALSE");

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while (getchar() != '\n');
			switch (reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("Program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first input.\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}

// Function(s)
void reversal(char *sentence, int sentence_length){
	char temp;
	char *p;
	char *mirror_p;
	for (p = sentence; p - sentence < sentence_length / 2 ; ++p){
		mirror_p = ((sentence + sentence_length - 1) - (p - sentence));
		temp = *p;
		*p = *mirror_p;
		*mirror_p = temp;
	}
}
