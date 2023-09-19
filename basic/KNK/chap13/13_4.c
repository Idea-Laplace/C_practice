/************************************************
 * 13-4 Modify the read_line funtion.           *
 * (a) Have it skip white space before beginning*
 *     to store input characaters.              *
 * (b) Have it stop reading at the first white  *
 *     space character.                         *
 * (c) Have it stop reading at the first new-   *
 *     line character, then store the new line  *
 *     character in the string.                 *
 * (d) Have it leave behind characters that it  *
 *     doesn't have room to store.              *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro
#define LENGTH 10
#define ID(a) read_line_##a

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
int read_line(char str[], int n);
int ID(a)(char str[], int n);
int ID(b)(char str[], int n);
int ID(c)(char str[], int n);
int ID(d)(char str[], int n);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char str[LENGTH + 1];
		char *p = str;

		printf("Enter a sentence: ");
		read_line(str, LENGTH);
		while (getchar() != '\n');

		printf("In the str[] array, it is stored as: ");
		while (*p)
			printf("%c", *p++);
		printf("\n");


		// (a)===============================================
		p = str;
		printf("Enter a sentence: ");
		ID(a)(str, LENGTH);
		printf("With nowhite version(a), it is stored as: ");
		while (*p)
			printf("%c", *p++);
		printf("\n");
		while (getchar() != '\n');

		// (b)===============================================
		p = str;
		printf("Enter a sentence: ");
		ID(b)(str, LENGTH);
		printf("With white-stop version(b), it is stored as: ");
		while (*p)
			printf("%c", *p++);
		printf("\n");
		while (getchar() != '\n');

		// (c)===============================================
		p = str;
		printf("Enter a sentence: ");
		ID(c)(str, LENGTH);
		printf("With newline-stop version(c), it is stored as: ");
		while (*p)
			printf("%c", *p++);
		printf("\n");
		while (getchar() != '\n');

		// (d)===============================================
		p = str;
		printf("Enter a sentence: ");
		ID(d)(str, LENGTH);
		printf("With leave behind char version, it is stored as: ");
		while (*p)
			printf("%c", *p++);
		printf("\n");
		while (getchar() != '\n');

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
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}

int ID(a)(char str[], int n){
	int ch;
	char *p = str;
	while ((ch = getchar()) != '\n' && (p - str) < n){
		if (isspace(ch))
			continue;
		*p++ = ch;
	}
	*p = '\0';
	return (int) (p - str);
}

int ID(b)(char str[], int n){
	int ch;
	char *p = str;
	while (!isspace(ch = getchar()) && (p - str) < n)
		*p++ = ch;
	*p = '\0';
	return (int) (p - str);
}

int ID(c)(char str[], int n){
	int ch = getchar();
	char *p = str;
	do{
		*p++ = ch;
	} while ((p - str) < n && (ch = getchar()) == '\n');
	*p = '\0';

	return (int) (p - str);
}
int ID(d)(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}
