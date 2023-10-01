#include <stdio.h>
#include "part.h"
#include "readline.h"

part inventory[MAX_PARTS];
int num_parts = 0;

int find_part(int number) {
	for (int i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(void) {
	int part_number;

	if (num_parts == MAX_PARTS) {
		printf("Database si full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);

	num_parts++;
}

void search(void) {
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);

	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void) {
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);

	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print(void) {
	printf("Part number\t" "Part name\t\t" "Quantity on hand\n");
	for (int i = 0; i < num_parts; i++) {
		printf("%7d\t\t""%-25s%11d\n", inventory[i].number, inventory[i].name,
				inventory[i].on_hand);
	}
}
