/************************************************
 * Programming Project 12-1                     *
 * Write a program that reads a message, then   *
 * prints the revesal of the message.           *
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
		// Main I/O
		char sentence[LENGTH];
		char *p = sentence;
		printf("Enter a sentence: ");
		while ((p - sentence) < LENGTH && (*p = getchar()) != '\n')
			++p;
		printf("Echo: ");
		for (char *q = sentence; q < p; ++q){
			printf("%c", *q);
		}
		printf("\n");

		reversal(sentence, (int) (p - sentence));
		printf("Reversal: ");
		for (char *q = sentence; q < p; ++q){
			printf("%c", *q);
		}
		printf("\n");
		while ((p - sentence) >= LENGTH && getchar() != '\n'); // Flush remain characters.



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
