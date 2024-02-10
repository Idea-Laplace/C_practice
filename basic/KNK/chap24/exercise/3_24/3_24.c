#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type {
	Item *contents;
	int top;
	int size;
};

Stack create(int size) {
	Stack s = malloc(sizeof(struct stack_type));
	// 3_24.c
	assert(s != NULL);

	s->contents = malloc(size * sizeof(Item));
	if (s->contents == NULL) {
		// 3_24.c
		free(s);
		// Since s needs to free, we would not use assert.
		fprintf(stderr, "Cannot allocate memory for stack contents\n");
		exit(EXIT_FAILURE);
	}

	s->top = 0;
	s->size = size;

	return s;
}

void destroy(Stack s) {
	free(s->contents);
	free(s);
}

void make_empty(Stack s) {
	s->top = 0;
}

bool is_empty(Stack s) {
	return s->top == 0;
}

bool is_full(Stack s) {
	return s->top == s->size;
}

void push(Stack s, Item i) {
	// 3_24.c
	if (is_full(s)) {
		fprintf(stderr, "Stack is full.\n");
		return;
	}
	s->contents[s->top++] = i;
}

Item pop(Stack s) {
	// 3_24.c
	if (is_empty(s)) {
		fprintf(stderr, "Stack is full.\n");
		return -1;
	}
	return s->contents[--s->top];
}
