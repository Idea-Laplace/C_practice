#ifndef STACKADT2_H
#define STACKADT2_H

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack create(int size);
void make_empty(Stack s);
void destroy(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif
