#include <stdio.h>
#include <stdlib.h>
#include "inventory_array_ver.h"
#include "readline.h"

int max_len = INITIAL_PARTS;
int num_len = 0;
struct part *inventory;

void init() {
	inventory = malloc(max_len * sizeof(struct part));
}


int find_part(int number) {
	for (int i = 0; i < num_len; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert() {
	int part_number;
	if (num_len == max_len) {
		struct part *temp;
		max_len *= 2;
		temp = realloc(inventory, max_len * sizeof(struct part));
		if (temp == NULL) {
			printf("Insufficient memory, cannot insert.\n");
			return;
		}
		inventory = temp;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);
	while (getchar() != '\n');

	if (find_part(part_number) >= 0) {
		printf("Number already exists.\n");
		return;
	}

	inventory[num_len].number = part_number;
	
	printf("Enter part name: ");
	readline(inventory[num_len].name, NAME_LEN);

	printf("Enter the on hand value: ");
	scanf("%d", &inventory[num_len].on_hand);
	while(getchar() != '\n');

	num_len++;
}


void search() {
	int part_number;
	int index;
	printf("Enter a part number you want to search: ");
	scanf("%d", &part_number);
	while (getchar() != '\n');

	index = find_part(part_number);
	if (index >= 0) {
		printf("Part name: %s\n", inventory[index].name);
		printf("Quantity on hand: %d\n", inventory[index].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update() {
	int part_number;
	int index;
	int change;
	printf("Enter a part number you want to search: ");
	scanf("%d", &part_number);

	index = find_part(part_number);
	if (index >= 0) {
		printf("Enter changes the on hand: ");
		scanf("%d", &change);
		inventory[index].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print_part() {
	printf("Part Number          Part Name          On Hand\n");
	printf("===============================================\n");
	for (int i = 0; i < num_len; i++)
		printf("    %3d     %25s    %3d\n", inventory[i].number,
				inventory[i].name, inventory[i].on_hand);
}

