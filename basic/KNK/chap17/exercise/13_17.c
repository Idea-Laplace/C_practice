struct node {
	int value;
	struct node *next;
};

struct node *insert_ordered_list(struct node *list, struct node *new_node) {
	struct node *cur = list, *prev = NULL;
	while (cur != NULL && cur->value <= new_node->value) {
		prev = cur;
		cur = cur->next;
	}

	if (prev == NULL) {
		new_node->next = list;
		list = new_node;
	}

	else {
		prev->next = new_node;
		new_node->next = cur;
	}

	return list;
}
