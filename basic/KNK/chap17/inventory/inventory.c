#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "../readline/readline.h"

struct part *find_part(struct part *inventory, int number) {
	struct part *p;
	for (p = inventory;
		p != NULL && number > p->number;
		p = p->next);

	if (p != NULL && number == p->number)
		return p;
	return NULL;
}

void insert(struct part *inventory) {
	struct part *cur, *prev, *new_node;

	// Error handling
	new_node = malloc(sizeof(struct part));
	if (new_node == NULL) {
		printf("Database if full, can't add more parts.\n");
		return;
	}

	printf("Enter new number: ");
	scanf("%d", &new_node->number);

	for (cur = inventory, prev = NULL;
		cur != NULL && new_node->number > cur->number;
		prev = cur, cur = cur->next);

	if (cur != NULL && cur->number == new_node->number) {
		printf("Part already exists, ignored.\n");
		// Free new_node
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", new_node->on_hand);

	new_node->next = cur;
	if (prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

void search(struct part *inventory) {
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);

	p = find_part(inventory, number);
	if (p == NULL)
		printf("Part not found.\n");
	else {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	}
}

void update(struct part *inventory) {
	int number, change;
	struct part *p;

	printf("Enter part name: ");
	scanf("%d", &number);

	p = find_part(inventory, number);
	if (p == NULL)
		printf("Part not found.\n");
	else {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	}
}

int compare_part(const void *p, const void *q) {
	return ((struct part *) p)->number - ((struct part *) q)->number;
}

void print_part(struct part *inventory) {
	struct part *p;
	printf("Part Number\t\t""Part Name\t\t""Quantity on hand\n");
	for (p = inventory; p != NULL; p = p->next)
		printf("%7d\t\t""%-25s\t\t""%11d\n", p->number, p->name, p->on_hand);
}

