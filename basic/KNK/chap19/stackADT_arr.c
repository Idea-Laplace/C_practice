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
	printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}

Stack create_arr_stk(int size) {
	Stack ptr_to_stk = malloc(sizeof(*ptr_to_stk));
	if (ptr_to_stk == NULL)
		terminate("Error in create: stack could not be created.");

	ptr_to_stk->contents = malloc(size * sizeof(ITEM));
	if (ptr_to_stk->contents == NULL) {
		free(ptr_to_stk);
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
	if (is_full(stk)) {
		stk->contents = realloc(stk->contents, 2 * stk->size);
		if (stk->contents == NULL) {
			free(stk);
			terminate("Error in push: stack is full.");
		}
		stk->size *= 2;
	}
	
	stk->contents[stk->top++] = value;
}

ITEM pop(Stack stk) {
	if (is_empty(stk))
		terminate("Error in pop: stack is empty.");
	return stk->contents[--stk->top];
}

ITEM peek(Stack stk) {
	if (is_empty(stk))
		printf("Stack is empty.\n");

	return stk->contents[stk->top];
}

void print_stk(Stack stk) {
	for (int i = 0; i < stk->top; i++) {
		printf("%2d->", stk->contents[i]);
	}
	printf("top\n");
}

int get_stk_size(Stack stk) {
	return stk->size;
}

int get_stk_top(Stack stk) {
	return stk->top;
}
