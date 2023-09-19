#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Macros for stack
#define STACK_SIZE 100

// Prototypes for stack
void make_empty(int *top);
bool is_empty(int *top);
bool is_full(int *top, int full_stack);
void push(int contents[], int value, int *top, int stack_size);
int pop(int contents[], int *top);

#endif
