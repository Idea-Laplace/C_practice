
struct node *delete_node(struct node *linked_list, int value) {
	struct node *previous;

	for (previous = NULL;
		linked_list != NULL && linked_list -> value != value;
		previous = linked_list, linked_list = linked_list -> next);

	if (previous == NULL)
		linked_list = linked_list -> next;
	else
		previous -> next = linked_list -> next;

	free(linked_list);

	return linked_list;
}
