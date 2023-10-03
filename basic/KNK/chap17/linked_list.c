#include <stdlib.h>
#include "linked_list.h"


void add_node(struct node **linked_list, int value) {
	struct node *new_node;
	new_node = malloc(sizeof(struct node));  // Be aware that malloc() does not free the block even after the function closed.
	if (new_node == NULL) {
		printf("Error: malloc failed in add_node.\n");
		exit(EXIT_FAILURE);
	}

	new_node -> value = value;
	new_node -> next = *linked_list;

	*linked_list = new_node;
}

struct node *search_node(struct node *linked_list, int value) {
	while (linked_list != NULL && linked_list -> value != value)
		linked_list = linked_list -> next;

	return linked_list;
}

struct node *delete_node(struct node *linked_list, int value) {
	struct node *current, *previous;

	for (current = linked_list, previous = NULL;
		current != NULL && current -> value != value;
		previous = current, current = current -> next);

	if (previous == NULL)
		linked_list = linked_list -> next;
	else
		previous -> next = current -> next;

	free(current);

	return linked_list;
}
	



