/************************************************
 * 16-13
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define LEN 100

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
int read_line(char str[], int n);
int count_space(const char str[]);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char str[LEN + 1];
		read_line(str, LEN);
		printf("Count space: %d\n", count_space(str));

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

int read_line(char str[], int n){
	int ch;
	char *p;
	puts("Enter a sentence.");
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}

int count_space(const char str[]){
	int count = 0;
	while (*str)
		if (isspace(*str++))
			++count;
	return count;
}

