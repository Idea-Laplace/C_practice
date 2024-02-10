/*
	Write a call of assert that causes a program to terminate 
	if a variable named top has the value NULL
*/

//#define NDEBUG // When activated, it would make assert disabled.
#include <assert.h>
#include <stdio.h>

struct node {
	int element;
	struct node *next;
} *stack;

struct node *top = NULL;

int main(void) {
	assert(top != NULL);
	printf("Program terminated normally.\n");
	return 0;
}
