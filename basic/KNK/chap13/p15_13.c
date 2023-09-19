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
#define FULL_STACK 30
#define MAX_EXPR 100
#define OPERATORS 5
// External Variable(s)

// Prototype(s)
// About input
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);

// Core process
int eval_rpn(const char *expression);
bool in_operators(const char operator);

// Stack
void make_empty(int *top);
bool is_empty(int *top);
bool is_full(int *top);
void push(int operands[], int *top, int operand);
int pop(int operands[], int *top);


// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char rpn_expression[MAX_EXPR + 1];
		int value;
		printf("Enter a RPN expression: ");
		read_line(rpn_expression, MAX_EXPR);
		value = eval_rpn(rpn_expression);
		printf("Answer: %d\n", value);


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

void make_empty(int *top) {
	*top = 0;
}

bool is_empty(int *top) {
	return *top == 0;
}

bool is_full(int *top) {
	return *top == FULL_STACK;
}

void push(int operands[], int *top, int operand) {
	if (is_full(top)) {
		printf("The stack is full, ignored.\n");
		return;
	}
	operands[(*top)++] = operand;

}

int pop(int operands[], int *top) {
	if (is_empty(top)) {
		printf("The stack is empty, ignored.\n");
		return 0;
	}
	return operands[(*top)-- - 1];
}

int eval_rpn(const char *expression) {
	int operands[FULL_STACK];
	int top = 0;
	while (*expression) {
		int calculation;
		if (isdigit(*expression)) {
			if (is_full(operands)) {
				printf("The given expression is too complex.\n");
				return -1;
			}
			push(operands, &top, (int) *expression - '0');
			++expression;
			continue;
		}

		switch (*expression) {
			case '+':
				calculation = pop(operands, &top);
				calculation += pop(operands, &top);
				push(operands, &top, calculation);
				break;
			case '-':
				calculation = -pop(operands, &top);
				calculation += pop(operands, &top);
				push(operands, &top, calculation);
				break;
			case '*':
				calculation = pop(operands, &top);
				calculation *= pop(operands, &top);
				push(operands, &top, calculation);
				break;
			case '/':
				int temp;
				temp = pop(operands, &top);
				if (!temp) {
					printf("Zero division error\n");
					return -1;
				}
				calculation = pop(operands, &top);
				calculation /= temp;
				push(operands, &top, calculation);
				break;
			case '=':
				calculation = pop(operands, &top);
				if (!is_empty(&top) || *(expression + 1)) {
					printf("Invalid expression.\n");
					return -1;
				}
				return calculation;
			case ' ': case '\t':
				break;
			default: 
				printf("Invalid expression.\n");
				return -1;
		}
		++expression;
	}
	printf("Invalid expression.\n");
	return -1;
}
