#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define PRIVATE static

struct stack_type {
	ITEM *contents;
	int top;
	int size;
};

PRIVATE void terminate(const char *error_msg) {
	printf("%s\n");
	exit(EXIT_FAILURE);
}

Stack create_arr_stk(int size) {
	Stack ptr_to_stk = malloc(sizeof(struct stack_type));
	if (ptr_to_stk == NULL)
		terminate("Error in create: stack could not be created.");

	ptr_to_stk->contents = malloc(size * sizeof(ITEM));
	if (ptr_to_stk->contents == NULL) {
		free(ptr_to_stk->contents);
		terminate("Error in create: stack could not be created.");
	}

	ptr_to_stk->top = 0;
	ptr_to_stk->size = size;
	return ptr_to_stk;
}

void destroy(Stack stk) {
	free(stk->contents);
	free(stk);
}

void make_empty(Stack stk) {
	stk->top = 0;
}

bool is_empty(Stack stk) {
	return stk->top == 0;
}

bool is_full(Stack stk) {
	return stk->top == stk->size;
}

void push(Stack stk, ITEM value) {
	if (is_full(stk))
		terminate("Error in push: stack is full.");
	stk->contents[stk->top++] = value;
}

ITEM pop(Stack stk) {
	if (is_empty(stk))
		terminate("Error in pop: stack is empty.");
	return stk->contents[--stk->top];
}
