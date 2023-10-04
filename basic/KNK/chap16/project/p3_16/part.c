#include <stdio.h>
#include "part.h"
#include "readline.h"


int find_part(int number, part inventory[], int *num_parts) {
	for (int i = 0; i < *num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(part inventory[], int *num_parts) {
	int part_number;
	int insertion_point;

	if (*num_parts == MAX_PARTS) {
		printf("Database si full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number, inventory, num_parts) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	// Find index where the insertion is done.
	for (insertion_point = 0; insertion_point < *num_parts; insertion_point++) {
		if (inventory[insertion_point].number > part_number)
			break;
	}

	// Push parts that has larger part number than that of insertion part.
	for (int i = *num_parts; i > insertion_point; i--)
		inventory[i] = inventory[i - 1];

	inventory[insertion_point].number = part_number;

	printf("Enter part name: ");
	read_line(inventory[insertion_point].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[insertion_point].on_hand);

	(*num_parts)++;
}

void search(part inventory[], int *num_parts) {
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, inventory, num_parts);

	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(part inventory[], int *num_parts) {
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, inventory, num_parts);

	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print(part inventory[], int *num_parts) {
	printf("Part number\t" "Part name\t\t" "Quantity on hand\n");
	for (int i = 0; i < *num_parts; i++) {
		printf("%7d\t\t""%-25s%11d\n", inventory[i].number, inventory[i].name,
				inventory[i].on_hand);
	}
}
