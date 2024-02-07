#include <stdio.h>
#include <stdlib.h>
#include "inventory2.h"

#define NAME_LEN 25
#define INTERNAL static
#define FLUSH while (getchar() != '\n')

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part *next;
};

INTERNAL int read_line(char *str, int len) {
	int ch;
	char *input = str;

	while ((ch = getchar()) != '\n' && (input - str) < len)
		*input++ = ch;
	*input = '\0';

	return (int) (input - str);
}



INTERNAL struct part *find_part(struct part *inventory, int number) {
	struct part *p;

	for (;inventory != NULL && number > inventory->number;
		inventory  = inventory->next);
	
	if (inventory != NULL && number == inventory->number)
		return inventory;
	return NULL;
}


void insert(struct part **inventory_addr) {
	struct part *cur, *prev, *new_node;

	if ((new_node = malloc(sizeof(*new_node))) == NULL) {
		fprintf(stderr, "Error, list is full.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->number);
	FLUSH;

	for (cur = *inventory_addr, prev = NULL;
		cur != NULL && new_node->number > cur->number;
		prev = cur, cur = cur->next);

	if (cur != NULL && cur->number == new_node->number) {
		printf("Part already exists.\n");
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);
	FLUSH;

	new_node->next = cur;

	if (prev == NULL)
		*inventory_addr = new_node;
	else 
		prev->next = new_node;
}


void search(struct part *inventory) {
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	FLUSH;
	p = find_part(inventory, number);

	if (p != NULL) {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(struct part *inventory) {
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(inventory, number);

	if (p != NULL) {
		printf("Enter change in quantity: ");
		scanf("%d", &number);
		FLUSH;
		p->on_hand += number;
	}
	else
		printf("Part not found.\n");
}

void print(struct part *inventory) {
	printf("   Part number             NAMES             Quantity on hand   \n");
	printf("   -----------   -------------------------   ----------------   \n");
	for (;inventory != NULL; inventory = inventory->next)
		printf("   %10d   %25s   %16d\n", inventory->number, inventory->name, inventory->on_hand);
}

void destroy(struct part *inventory) {
	struct part *remove = inventory, *old = inventory;
	while (old != NULL) {
		old = old->next;
		free(remove);
		remove = old;
	}
}

void dump(struct part *inventory) {
	char filename[L_tmpnam];
	FILE *fp;
	printf("Enter name of output file: ");
	read_line(filename, L_tmpnam);

	if ((fp = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "Error, save file cannot be created.\n");
		return;
	}

	for (; inventory != NULL; inventory = inventory->next)
		fprintf(fp, "%d,%25s,%d\n", inventory->number, inventory->name, inventory->on_hand);

	fclose(fp);
	printf("Saved.\n");
}

void restore(struct part **inventory_addr) {
	char filename[L_tmpnam];
	FILE *fp;
	int success;
	struct part *p, *store_next;
	struct part *pos;


	printf("Enter name of input file: ");
	read_line(filename, L_tmpnam);

	if ((fp = fopen(filename, "rb")) == NULL) {
		fprintf(stderr, "Error, save file cannot be called.\n");
		return;
	}

	destroy(*inventory_addr);
	*inventory_addr = NULL;

	for (;;) {
		if ((p = malloc(sizeof(*p))) == NULL) {
			printf("Restore failed, memory issue.\n");
			return;
		}

		success = fscanf(fp, "%d,%25[^,],%d", &p->number, p->name, &p->on_hand);
		if (success != 3 && feof(fp)) {
			free(p);
			fclose(fp);
			printf("Restored.\n");
			return;
		}
		else if (success != 3) {
			if (ferror(fp))
				printf("Restore error.\n");
			else
				printf("Error unknown.\n");
			fclose(fp);
			free(p);
			exit(EXIT_FAILURE);
		}

		p->next == NULL;

		if (*inventory_addr == NULL)
			*inventory_addr = p;
		else
			pos->next = p;
		pos = p;
	}
}
