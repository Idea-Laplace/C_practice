/************************************************
 * p1_13, Input words should be lower case.     *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define LEN 20
#define MAX_ASCII "\177"

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
int read_line_nowhite(char str[], int n);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char word[LEN + 1];
		char largest[LEN + 1] = "\0", smallest[LEN + 1] = MAX_ASCII; 
		do {
			read_line_nowhite(word, LEN);    // Input words should be lower case.
			if (strcmp(smallest, word) > 0)
				strcpy(smallest, word);
			if (strcmp(word, largest) > 0)
				strcpy(largest, word);
		} while (strlen(word) != 4);
		putchar('\n');
		printf("Smallest word: %s\n", smallest);
		printf("Largest word: %s\n", largest);

		// Loop decision
		loop_decision(&loop);
	}
	system("pause");
	return 0;
}

// Function(s)
void loop_decision(bool *loop){
	int reply;
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

int read_line_nowhite(char str[], int n){
	int ch;
	char *p;
	printf("Enter a word: ");
	for (p = str; !isspace(ch = getchar()) && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return strlen(str);
}
