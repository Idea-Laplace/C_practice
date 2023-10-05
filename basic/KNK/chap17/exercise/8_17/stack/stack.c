#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool push(struct stack *st, int value) {
	struct node *new_node;
	new_node = malloc(sizeof(new_node));
	if (new_node == NULL) {
		printf("malloc() failed, push ignored.\n");
		return false;
	}
	
	new_node -> value = value;
	new_node -> next = st -> top;
	st -> top = new_node;
	(st -> depth)++;

	return true;
}

int pop(struct stack *st) {
	struct node *pop = st -> top;
	int pop_value = st -> top -> value;

	if (st -> top != NULL) {
		st -> top = st -> top -> next;
		free(pop);
		(st -> depth)--;

		return pop_value;
	}

	else {
		printf("The stack is empty, -1 returned.\n");
		return -1;
	}
}


int depth(struct stack st) {
	return st.depth;
}


void print_stack(struct stack st) {
	while (st.top != NULL) {
		printf("| %5d |\n", st.top -> value);
		printf("---------\n");
		st.top = st.top -> next;
	}
}
