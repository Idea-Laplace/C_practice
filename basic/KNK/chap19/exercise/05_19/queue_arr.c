#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define QUEUE_SIZE 100
#define PRIVATE static

struct queue {
	ITEM contents[QUEUE_SIZE];
	int entrance;
	int exit;
	int elements;
};

PRIVATE void terminate(char *error_msg) {
	printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}


Queue create_queue(void) {
	Queue new_queue;
	new_queue = malloc(sizeof(struct queue));

	if (new_queue == NULL)
		terminate("Error in create_queue: queue could not be created.");

	new_queue->entrance = 0;
	new_queue->exit = 0;
	new_queue->elements = 0;

	return new_queue;
}

void destory_queue(Queue qu) {
	free(qu);
}

bool insert_item_queue(Queue qu, ITEM data) {
	if (qu->elements == QUEUE_SIZE) {
		printf("Cannot add item, queue is full.\n");
		return false;
	}

	qu->contents[qu->entrance++] = data;
	qu->entrance %= QUEUE_SIZE;

	qu->elements++;
}

ITEM pop_item_queue(Queue qu) {
	ITEM poped_item;
	if (is_empty_queue(qu))
		terminate("Error in pop_item_queue: queue is empty.");

	poped_item = qu->contents[qu->exit++];
	qu->exit %= QUEUE_SIZE;

	qu->elements--;

	return poped_item;
}

ITEM check_entrance_queue(Queue qu) {
	if (is_empty_queue(qu))
		terminate("Error in check_entrance_queue: queus is empty.");
	return qu->contents[qu->entrance - 1];
}

ITEM check_exit_queue(Queue qu) {
	if (is_empty_queue(qu))
		terminate("Error in check_entrance_queue: queus is empty.");
	return qu->contents[qu->exit];
}

void make_empty_queue(Queue qu) {
	qu->entrance = 0;
	qu->exit = 0;
	qu->elements = 0;
}

bool is_empty_queue(Queue qu) {
	return qu->elements == 0;
}

void print_qu(Queue qu) {
	int search = qu->exit;
	printf("Old<-");

	while (search % QUEUE_SIZE != qu->entrance) {
		printf("%2d<-", qu->contents[search]);
		search++;
	}

	printf("New\n");
}
