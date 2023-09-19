// Test the validty of nested parentheses using stack ADT.
// Calculate an Reverse Polish Notation (RPN) expression by exploiting stack.
// Operands will be single-digit.
#include <stdio.h>
#include <stdbool.h> // C99 standard
#include "stack.h"
#include "rpn.h"
#include "template.h"


// Main
int main(void) {
	bool loop = true;
	while (loop) {
		int contents[STACK_SIZE];
		int top = 0;               // Keep in mind that top - 1 is used as index
		char entry;
		int value;
		bool valid_expr = true;

		make_empty(&top);
		printf("Enter an RPN expression: ");
		while ((entry = getchar()) != '\n' && valid_expr) {
			if (is_number(entry) && !is_full(&top, STACK_SIZE))
				push(contents, entry - '0', &top, STACK_SIZE);
			else if(is_full(&top, STACK_SIZE)) {
				printf("Expression is too complex.\n");
				break;
			}

			else if (is_operator(entry)) {
				switch (entry) {
					case '=':
						if (top == 0) {
							printf("Not enough operands in expression.\n");
							while (getchar() != '\n');
							valid_expr = false;
							break;
						}
						value = pop(contents, &top);
						break;
					if (top == 1) {
						printf("Not enough operands in expression.\n");
						while (getchar() != '\n');
						valid_expr = false;
						break;
					}
					case '+':
						value = pop(contents, &top);
						value += pop(contents, &top);
						push(contents, value, &top, STACK_SIZE);
						break;
					case '-':
						value = -pop(contents, &top);
						value += pop(contents, &top);
						push(contents, value, &top, STACK_SIZE);
						break;
					case '*':
						value = pop(contents, &top);
						value *= pop(contents, &top);
						push(contents, value, &top, STACK_SIZE);
						break;
					case '/':
						value = pop(contents, &top);
						if (value == 0) {
							printf("Zero division error.\n");
							while (getchar() != '\n');
							valid_expr = false;
							break;
						}
						value = pop(contents, &top) / value;
						push(contents, value, &top, STACK_SIZE);
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
		printf("Value of expression: %d\n", is_empty(&top) ? value : -1);

		// Loop decision
		loop_decision(&loop);
	}

	return 0;
}

