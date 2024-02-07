#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

#define FLUSH while (getchar() != '\n')

// Gloabal variables
struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

// Prototypes
	// basic
void insert(void);
void search(void);
void update(void);
void remove_part(void);
void flush(void);
void print(void);

	// File I/O
void dump(void);
void open(void);

int main(void) {
	char code;
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n');

		switch (code) {
			case 'i': insert(); break;
			case 's': search(); break;
			case 'u': update(); break;
			case 'r': remove_part(); break;
			case 'f': flush(); break;
			case 'p': print(); break;
			case 'd': dump(); break;
			case 'o': open(); break;
			case 'q': 
					printf("Process terminated.\n");
					return 0;
			default : 
					printf("Invalid code\n");
					break;
		}
	}
	printf("\n");
}

int read_line(char str[], int len) {
	int ch;
	int num = 0;
	while ((ch = getchar()) != '\n') {
		if (num >= len)
			continue;

		str[num++] = ch;
	}
	str[num] = '\0';
	return num;
}

int find_part(int number) {
	int i = 0;
	for (; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(void) {
	int part_number;
	int pos;

	// Exception handling
	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	// Input
	printf("Enter part number: ");
	scanf("%d", &part_number);
	FLUSH;

	// Duplication check
	if (find_part(part_number) >= 0) {
		printf("Part %d already exists.\n", part_number);
		return;
	}

	// Rearrangement process
	for (pos = 0; pos < num_parts && inventory[pos].number < part_number; pos++);
	for (int shift = num_parts - 1; shift >= pos; shift--)
		inventory[shift + 1] = inventory[shift];

	// Uploading data
	inventory[pos].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[pos].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[pos].on_hand);
	FLUSH;

	// Increase num_parts
	num_parts++;
}

void search(void) {
	int part_number;
	int idx;

	// Input
	printf("Enter part number: ");
	scanf("%d", &part_number);
	FLUSH;

	if ((idx = find_part(part_number)) < 0) {
		printf("No part number %d exists.\n", part_number);
		return;
	}

	printf("Part name: %s\n", inventory[idx].name);
	printf("Quantity on hand: %d\n", inventory[idx].on_hand);
}

void update(void) {
	int part_number, idx, change;

	// Input
	printf("Enter part number: ");
	scanf("%d", &part_number);
	FLUSH;

	if ((idx = find_part(part_number)) < 0) {
		printf("No part number %d exists.\n", part_number);
		return;
	}

	printf("Enter change in quantity on hand: ");
	scanf("%d", &change);
	FLUSH;
	inventory[idx].on_hand += change;
}

void remove_part(void) {
	int part_number, idx;

	// Input
	printf("Enter part number: ");
	scanf("%d", &part_number);
	FLUSH;

	if ((idx = find_part(part_number)) < 0) {
		printf("No datum of part number %d exists.\n", part_number);
		return;
	}
	
	// Remove by rearragement
	for (int k = idx; k < num_parts - 1; k++)
		inventory[k] = inventory[k + 1];
	num_parts--;
}

void flush(void) {
	num_parts = 0;
}

void print(void) {
	int i;

	printf("Part Number           Part Name           Quantity on Hand\n");
	printf("-----------   -------------------------   ----------------\n");
	for (i = 0; i < num_parts; i++)
		printf("%10d ""   %25s   ""%15d \n",\
				inventory[i].number, inventory[i].name, inventory[i].on_hand);
	printf("\n");
}

void dump(void) {
	FILE *fp;
	char filename[L_tmpnam];
	printf("Enter filename to save current data: ");
	read_line(filename, L_tmpnam - 1);

	if ((fp = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "File %s cannot be created.\n", filename);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < num_parts; i++)
		fwrite(inventory + i, sizeof(*inventory), 1, fp);

	printf("Saved in %s.\n", filename);
}


void open(void) {
	FILE *fp;
	int i = 0;
	char filename[L_tmpnam];
	printf("Enter filename to call: ");
	read_line(filename, L_tmpnam - 1);

	if ((fp = fopen(filename, "rb")) == NULL) {
		fprintf(stderr, "File %s cannot be opened.\n", filename);
		exit(EXIT_FAILURE);
	}

	flush();

	while (fread(inventory + i++, sizeof(*inventory), 1, fp) == 1)
		num_parts++;

	printf("Data restored from %s.\n", filename);
}
