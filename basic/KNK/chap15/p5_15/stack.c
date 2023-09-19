#include "stack.h"
#include <stdio.h>

void make_empty(int *top) {
	*top = 0;
}

bool is_empty(int *top) {
	return *top == 0;
}

bool is_full(int *top, int full_stack) {
	return *top == full_stack;
}

void push(int contents[], int value, int *top, int full_stack) {
	if (is_full(top, full_stack))
		printf("Error: stack overflow.\n");
	else
		contents[(*top)++] = value;
}

int pop(int contents[], int *top) {
	if (is_empty(top)) {
		printf("Error: stack underflow.\n");
		return 'E';
	}
	else
		return contents[--(*top)];
}

