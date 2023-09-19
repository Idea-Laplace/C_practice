/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define LOOP_MESSAGE "Loop this program?(y/n): "
#define TERMINATE_MESSAGE "Program terminated.\n"
#define MAX_LEN 100
// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);
int compute_scrabble_value(const char *word);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		int scrabble = 0;
		char word[MAX_LEN + 1];

		printf("Enter a word: ");
		read_line(word, MAX_LEN);
		printf("Scrabble value: %d\n", compute_scrabble_value(word));

		// Loop decision
		loop_decision(&loop, LOOP_MESSAGE, TERMINATE_MESSAGE);
	}
	system("pause");
	return 0;
}

// Function(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message){
	int reply;
	do {
		printf("%s", loop_message);
		reply = toupper(getchar());
		while (getchar() != '\n');
		switch (reply){
			case 'Y': printf("\n===================================\n"); break;
			case 'N': printf("\n===================================\n");
					  printf("%s", terminate_message);
					  *loop = false;
					  break;
			default : printf("Type y[Y] or n[N] on the first input.\n"); break;
		}
	} while (reply != 'Y' && reply != 'N');
}

int read_line(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}

int compute_scrabble_value(const char *word){
	int scrabble = 0;
	while (*word) {
		switch (toupper(*word++)) { 
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
	return scrabble;
}
