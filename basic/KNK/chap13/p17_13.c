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
#define LENGTH 100
// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);
bool is_palindrome(const char *sentence);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char sentence[LENGTH + 1];
		printf("Enter a sentence: ");
		read_line(sentence, LENGTH);
		if (is_palindrome(sentence))
			printf("The given sentence is palindrome.\n");
		else
			printf("The given sentence is not palindrome.\n");

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

bool is_palindrome(const char *sentence) {
	char alphabet_only[LENGTH + 1];
	char *p = alphabet_only;
	while (*sentence) {
		if (isalpha(*sentence))
			*p++ = toupper(*sentence);
		++sentence;
	}
	for (int i = 0; i < (p - alphabet_only) / 2; ++i)
		if (*(alphabet_only + i) != *(p - 1 - i))
			return false;
	return true;
}

