// Test the validty of nested parentheses using stack ADT.
// Calculate an Reverse Polish Notation (RPN) expression by exploiting stack.
// Operands will be single-digit.
#include <stdio.h>
#include <stdlib.h> // system()
#include <ctype.h>  // toupper()
#include <stdbool.h> // C99 standard

// Macro
#define STACK_SIZE 100
#define NUM_OPERATOR 5

// External variable
char contents[STACK_SIZE];
int top = 0;               // Keep in mind that top - 1 is used as index

// Prototypes - for stack
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);

// Prototypse - for RPN
bool is_operator(char operator);
bool is_number(char number);


// Main
int main(void) {
	for(;;) {
		char entry;
		int value;

		make_empty();
		printf("Enter an RPN expression: ");
		while ((entry = getchar()) != '\n') {
			if (is_number(entry) && !is_full())
				push(entry);
			else if(is_full()) {
				printf("Expression is too complex.\n");
				break;
			}

			else if (is_operator(entry)) {
				switch (entry) {
					case '=':
						if (top == 0) {
							printf("Not enough operands in expression.\n");
							while (getchar() != '\n');
							goto out;
						}
						value = pop() - '0';
						break;
					if (top == 1) {
						printf("Not enough operands in expression.\n");
						while (getchar() != '\n');
						goto out;
					}
					case '+':
						value = pop() - '0';
						value += pop() - '0';
						push(value + '0');
						break;
					case '-':
						value = - pop();
						value += pop();
						push(value + '0');
						break;
					case '*':
						value = pop() - '0';
						value *= pop() - '0';
						push(value + '0');
						break;
					case '/':
						value = pop() - '0';
						if (value == 0) {
							printf("Zero division error.\n");
							while (getchar() != '\n');
							goto out;
						}
						value = (pop() - '0') / value;
						push(value + '0');
						break;
					default:
						break;
				}
			}
			else if (entry == ' ');
			else {
				printf("Unexpected expression, session terminated.\n");
				while (getchar() != '\n');
				break;
			}
		}
		out:
		printf("Value of expression: %d\n", is_empty() ? value : -1);



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

bool is_operator(char operator) {
	const char operator_arr[NUM_OPERATOR] = {'+', '-', '*', '/', '='};
	for (int i = 0; i < NUM_OPERATOR; i++)
		if (operator == operator_arr[i])
			return true;
	return false;
}

bool is_number(char number) {
	for (char ch = '0'; ch <= '9'; ch++)
		if (number == ch)
			return true;
	return false;
}
