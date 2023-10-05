#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Struct
struct node {
	int value;
	struct node *next;
};

void add_node(struct node **linked_list, int value);
struct node *search_node(struct node *linked_list, int value);
struct node *delete_node(struct node *linked_list, int value);

#endif
