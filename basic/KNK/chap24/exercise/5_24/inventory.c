#include <ctype.h>
#include <stdio.h>


#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1 + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

static int find_part(int number) {
	for (int i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

static int readline(char *str, int len) {
	int i, ch;

	while (isspace(ch = getchar()));

	while (ch != '\n' && ch != EOF) {
		if (i < len)
			str[i++] = ch;
		if (i == len)
			str[i++] = '*';
		ch = getchar();
	}
	str[i] = '\0';

	return i;
}


void insert(void) {
	int part_number;

	if (num_parts == MAX_PARTS) {
		fprintf(stderr, "Database is full; can't add more parts.\n");
		return;
	}
	printf("Enter part number: ");
	scanf("%d", &part_number);
	while (getchar() != '\n');

	if (find_part(part_number) >= 0) {
		fprintf(stderr, "Part alreadly exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	readline(inventory[num_parts].name, NAME_LEN);

	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	while (getchar() != '\n');
	num_parts++;
}

void search(void) {
	int i, number;
	printf("Enter part number: ");
	scanf("%d", &number);
	while(getchar() != '\n');

	i = find_part(number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantitiy on hand:  %d\n", inventory[i].on_hand);
	} else
		printf("Part not found.\n");
}

void update(void) {
	int i, number, change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	while(getchar() != '\n');

	i = find_part(number);
	if (i >= 0) {
		printf("Enter changes in quantitiy on hand: ");
		scanf("%d", &change);
		while (getchar() != '\n');
		inventory[i].on_hand += change;
	} else
		printf("Part not found.\n");
}

void print(void) {
	int i;
	printf("Part Number           Part Name           Quantity on Hand\n");
	printf("-----------   -------------------------   ----------------\n");
	for (i = 0; i < num_parts; i++) 
		printf("%11d   %25.25s   %16d\n", inventory[i].number, inventory[i].name,\
				inventory[i].on_hand);
}

