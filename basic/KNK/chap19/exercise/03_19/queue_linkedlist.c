#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define PRIVATE static

struct node {
	ITEM data;
	struct node *next;
};

struct queue {
	struct node *new;
	struct node *old;
};

PRIVATE void terminate(char *error_msg) {
	printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}

Queue create_queue(void) {
	struct queue *qu;
	qu = malloc(sizeof(struct queue));

	if (qu == NULL)
		terminate("Error in create_queue: could not create a queue.");

	qu->new = NULL;
	qu->old = NULL;

	return qu;
}

void destory_queue(Queue qu) {
	make_empty_queue(qu);
	free(qu);
}

bool insert_item_queue(Queue qu, ITEM data) {
	struct node *new_node;
	new_node = malloc(sizeof(struct node));

	if (new_node == NULL) {
		printf("Data could not be added, queue is full.\n");
		return false;
	}

	new_node->data = data;
	new_node->next = NULL;

	if (qu->old == NULL)
		qu->old = new_node;

	if (qu->new == NULL) {
		qu->new = new_node;
		return true;
	}

	qu->new->next = new_node;
	qu->new = new_node;
	return true;
}


ITEM pop_item_queue(Queue qu) {
	ITEM pop;
	struct node *remove;

	if (is_empty_queue(qu)) {
		terminate("Queue is empty.\n");
	}

	remove = qu->old;
	pop = remove->data;
	qu->old = qu->old->next;

	if (remove == qu->new)
		qu->new = NULL;

	free(remove);

	return pop;
}

ITEM check_new_queue(Queue qu) {
	return qu->new->data;
}

ITEM check_old_queue(Queue qu) {
	return qu->old->data;
}

void make_empty_queue(Queue qu) {
	while (!is_empty_queue(qu))
		pop_item_queue(qu);
}

bool is_empty_queue(Queue qu) {
	return (qu->old == NULL) && (qu->new == NULL);
}

void print_qu(Queue qu) {
	printf("Old");
	for (struct node *search = qu->old;
		search != NULL;
		search = search->next)
		printf("<-%2d", search->data);
	printf("<-New");
	printf("\n");
}
