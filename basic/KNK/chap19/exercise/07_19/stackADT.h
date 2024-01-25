#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;  // Like a class
typedef int ITEM;		// A clever stratege for maintenance.

Stack create(void);
Stack create_arr_stk(int size);
void destroy(Stack stk);
void make_empty(Stack stk);
bool is_empty(Stack stk);
bool is_full(Stack stk);
void push(Stack stk, ITEM value);
ITEM pop(Stack stk);
ITEM peek(Stack stk);
int get_stk_top(Stack stk);
int get_stk_size(Stack stk);
void print_stk(Stack stk);

#endif
