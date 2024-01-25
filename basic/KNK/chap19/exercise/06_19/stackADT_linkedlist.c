#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define PRIVATE static

struct node {
	ITEM data;
	struct node *next;
};

struct stack_type {
	struct node *top;
};

PRIVATE void terminate(const char *error_msg) {
	printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}

Stack create(void) {
	struct stack_type *stk;
	stk = malloc(sizeof(struct stack_type));
	if (stk == NULL)
		terminate("Error in create: stack could not be created.");
	stk->top = NULL;

	return stk;
}

void destroy(Stack stk) {
	make_empty(stk);
	free(stk);
}

void make_empty(Stack stk) {
	while (!is_empty(stk))
		pop(stk);
}

bool is_empty(Stack stk) {
	return stk->top == NULL;
}

bool is_full(Stack stk) {
	return false;
}

void push(Stack stk, ITEM value) {
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in push: stack is full.");

	new_node->data = value;
	new_node->next = stk->top;
	stk->top = new_node;
}

ITEM pop(Stack stk) {
	struct node *old_top;
	ITEM pop_val;

	if (is_empty(stk))
		terminate("Error in pop: stack is empty.");

	old_top = stk->top;
	pop_val = old_top->data;
	stk->top = old_top->next;
	free(old_top);
	
	return pop_val;
}

ITEM peek(Stack stk) {
	return stk->top->data;
}
