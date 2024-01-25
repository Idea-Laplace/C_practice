#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;  // Like a class
typedef char ITEM;		// A clever stratege for maintenance.

Stack create(void);
void destroy(Stack stk);
void make_empty(Stack stk);
bool is_empty(Stack stk);
bool is_full(Stack stk);
bool push(Stack stk, ITEM value);
ITEM pop(Stack stk);
ITEM peek(Stack stk);
void print_stk(Stack stk);

#endif
