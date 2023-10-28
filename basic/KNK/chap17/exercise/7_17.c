/**
 * The following loop is supposed to delete all nodes from a
 * linked list and release the memory that they occupy.
 * Unfortunately, dthe the loop is incorrect. Explain what's wrong with it
 * and show how to fix the bug.
 *
 * for (p = first; p != NULL; p = p -> next)
 *     free(p);
 **/

// You cannot access the struct using -> after free the block.



void delete_all_nodes(struct node *linked_list) {
	struct node previous;

	while (linked_list != NULL) {
		previous = linked_list;
		linked_list = linked_list -> next;
		free(previous);
	}
}
