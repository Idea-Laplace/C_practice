// This program organizes the abstract data structure 'stack'.
#include <stdio.h>
#include <stdlib.h> // system()
#include <ctype.h>  // toupper()
#include <stdbool.h> // C99 standard

// Macro
#define STACK_SIZE 100

// External variable
int contents[STACK_SIZE];
int top = 0;

// Prototype
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);

// Main
int main(void) {
	for(;;) {
		char command;
		int element;
		bool session = true;
		do {
			printf("Enter [m/e/f/i/o/b/p] to handle stack: ");
			command = getchar();
			while (getchar() != '\n');

			switch (command) {
				case 'm': make_empty(); break;
				case 'e': is_empty(); break;
				case 'f': is_full(); break;
				case 'o': pop(); break;
				case 'i': 
					printf("Enter a number to push in the stack: ");
					scanf("%d", &element);
					while (getchar() != '\n');
					push(element);
					break;
				case 'p': printf("Top: %d\n", contents[top - 1]); break;
				case 'b' :printf("Session terminated.\n"); session = false; break;
				default : printf("Undefined input, ignored.\n"); break;
			}
		} while (session);

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

void push(int i) {
	if (is_full())
		printf("Error: stack overflow.\n");
	else
		contents[top++] = i;
}

int pop(void) {
	if (is_empty())
		printf("Error: stack underflow.\n");
	else
		return contents[--top];
}
