/************************************************
 * 13-5
 * Capitalize
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
void loop_decision(bool *loop);
void capitalize(char str[], int n);
void capitalize_subscript(char str[], int n);

// Main
int main(void){
	bool loop = true;
	char str[LENGTH + 1];
	char *p;

	printf("Enter a sentence: ");
	for (p = str; (*p = getchar()) != '\n' && p - str < LENGTH; ++p);
	*p = '\0';
	if (p - str >= LENGTH)
		while (getchar() != '\n');

	printf("%s\n", str);
	capitalize_subscript(str, LENGTH);
	printf("Capitalized: %s\n", str);

	while (loop){
		// Main I/O

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

void capitalize(char str[], int n){
	for (char *p = str; (p - str) < n; ++p)
		*p = toupper(*p);
	return;
}
void capitalize_subscript(char str[], int n){
	for (int i = 0; i < n; ++i)
		str[i] = toupper(str[i]);
	return;
}
