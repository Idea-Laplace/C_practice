// Test the validty of nested parentheses using stack ADT.
#include <stdio.h>
#include <stdlib.h> // system()
#include <ctype.h>  // toupper()
#include <stdbool.h> // C99 standard

// Macro
#define STACK_SIZE 100

// External variable
char contents[STACK_SIZE];
int top = 0;               // Keep in mind that top - 1 is used as index

// Prototype
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);

// Main
int main(void) {
	for(;;) {
		char parenthese;
		bool final_check = true;

		make_empty();
		printf("Enter parentheses and/or braces: ");
		while ((parenthese = getchar()) != '\n') {
			if (parenthese == '(' || parenthese == '{')
				push(parenthese);
			if (parenthese == ')') 
				if (is_empty() || pop() != '(') {
					printf("Parentheses/braces are not nested properly.\n");
					final_check = false;
					break;
				}
			if (parenthese == '}') 
				if (is_empty() || pop() != '{') {
					printf("Parentheses/braces are not nested properly.\n");
					final_check = false;
					break;
				}
		}

		if (final_check) {
			if (!is_empty())
				printf("Parentheses/braces are not nested properly.\n");
			else
				printf("Parentheses/braces are nested properly.\n");
		}



		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch (reply) {
				case 'Y': printf("\n=========================\n"); break;
				case 'N': printf("Program terminated.\n"); goto end;
				default : printf("Type y[Y] or n[N].\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	end:
	system("pause");
	return 0;
}

void make_empty(void) {
	top = 0;
}

bool is_empty(void) {
	return top == 0;
}

bool is_full(void) {
	return top == STACK_SIZE;
}

void push(char ch) {
	if (is_full())
		printf("Error: stack overflow.\n");
	else
		contents[top++] = ch;
}

char pop(void) {
	if (is_empty()) {
		printf("Error: stack underflow.\n");
		return 'E';
	}
	else
		return contents[--top];
}
