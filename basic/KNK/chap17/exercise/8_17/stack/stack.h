#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "../linked_list/linked_list.h"

struct stack {
	struct node *top;
	int depth;
};

bool push(struct stack *st, int value);
int pop(struct stack *st);
int depth(struct stack st);
void print_stack(struct stack st);

#endif
