/**
 * Write the following function
 * int count_occurences(struct node *list, int n);
 * The list parameter points to a linked list. The function
 * should return a number of times that n appears in the list.
 * Assume that the node structure is the one defined in section 17.5
 **/


#include <stdio.h>

struct node {
	int value;
	struct node *next;
};


int count_occurences(struct node *list, int n) {
	int count = 0;

	while (list != NULL) {
		if (list -> value == n)
			++count;
		list = list -> next;
	}

	return count;
}


