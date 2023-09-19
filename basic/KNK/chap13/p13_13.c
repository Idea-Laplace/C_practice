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
#define MAX_LEN 200
#define ALPHABET 26
// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);
void encrypt(char *message, int shift);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char sentence[MAX_LEN + 1];
		int shift;
		printf("Enter a sentence: ");
		read_line(sentence, MAX_LEN);
		printf("Enter an interger to shift: ");
		scanf("%d", &shift);
		while (getchar() != '\n');
		encrypt(sentence, shift);
		printf("After encrypted by shift %d: %s\n", shift, sentence);


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

void encrypt(char *message, int shift) {
	while (*message) {
		if (isalpha(*message)) {
			if (*message > 'Z')
				*message = 'a' + ((*message + shift - 'a') % ALPHABET);
			else
				*message = 'A' + ((*message + shift - 'A') % ALPHABET);
		}
		++message;
	}
}
