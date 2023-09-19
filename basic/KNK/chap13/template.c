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

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char string[LENGTH + 1];

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
