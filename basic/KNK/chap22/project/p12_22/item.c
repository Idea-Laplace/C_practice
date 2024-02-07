#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item_info {
	int number;
	float unit_price;
	int purchase_date[3];
	struct item_info *next;
} *catalog;

catalog = NULL;


int find_item(int number) {
	struct item_info *p = catalog;

	for (; p != NULL; p = p->next)
		if (p->number == number)
			return number;
	return -1;
}

void insert(FILE *fp) {
	struct item_info *new_item;
	if ((new_item = malloc(sizeof(*new_item))) == NULL) {
		fprintf(stderr, "Error: cannot add to list, memory is full.\n");
		exit(EXIT_FAILURE);
	}

	fread(&new_item.number, sizeof(int), 1, fp);
	fined




