// Modify inventory.c
#include <stdio.h>
#include <stdlib.h>
#include "../readline/readline.h"
#include "../inventory/inventory.h"


int main(void) {
	char code;
	struct part *inventory = NULL;
	
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n');

		switch (code) {
			case 'i': insert(&inventory); break;
			case 's': search(inventory); break;
			case 'u': update(inventory); break;
			case 'p': print_part(inventory); break;
			case 'q': return 0;
			default : printf("Illegal code.\n");
		}
		puts("");
	}
}

int readline(char *str, int max_len) {
	char ch;
	int len = 0;
	while ((ch = getchar()) != '\n' && len < max_len) {
		*str++ = ch;
		len++;
	}
	*str = '\0';
	return len;
}


struct part *find_part(struct part *inventory, int number) {
	struct part *p;
	for (p = inventory;
		p != NULL && number > p->number;
		p = p->next);

	if (p != NULL && number == p->number)
		return p;
	return NULL;
}

void insert(struct part **inventory_address) {
	struct part *cur, *prev, *new_node;

	// Error handling
	new_node = malloc(sizeof(struct part));
	if (new_node == NULL) {
		printf("Database if full, can't add more parts.\n");
		return;
	}

	printf("Enter new number: ");
	scanf("%d", &new_node->number);
	while (getchar() != '\n');

	for (cur = *inventory_address, prev = NULL;
		cur != NULL && new_node->number > cur->number;
		prev = cur, cur = cur->next);

	if (cur != NULL && cur->number == new_node->number) {
		printf("Part already exists, ignored.\n");
		// Free new_node
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	readline(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);
	while (getchar() != '\n');

	new_node->next = cur;
	if (prev == NULL)
		*inventory_address = new_node;
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

