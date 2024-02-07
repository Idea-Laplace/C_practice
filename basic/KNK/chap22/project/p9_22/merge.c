#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro
#define NAME_LEN 25
#define MAX_PARTS 100

// Global variable
struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

FILE **merge_catalog;

// Prototypes
void update(FILE *fp);


int main(int argc, char **argv) {
	FILE *merged_fp;
	int i;

	// Error Handling ----------------------------------------------------------
	if (argc < 3) {
		fprintf(stderr, "Usage: $./merge {filename1} {filename2} [{filename3} ...]\n");
		exit(EXIT_FAILURE);
	}

	merge_catalog = malloc((argc - 1) * sizeof(FILE *));

	if (merge_catalog == NULL) {
		fprintf(stderr, "Error: cannot spare memory for file pointers.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < argc - 1; i++) {
		merge_catalog[i] = fopen(argv[i + 1], "rb");
		if (merge_catalog[i] == NULL) {
			fprintf(stderr, "Error: file %s cannot be opened.\n", argv[i + 1]);
			for (int j = 0; j < i; j++)
				fclose(merge_catalog[j]); 
			free(merge_catalog);
			exit(EXIT_FAILURE);
		}
	}

	merged_fp = fopen("merged_file.dat", "wb+");
	if (merged_fp == NULL) {
		fprintf(stderr, "Error: cannot create merge file.\n");
		for (i = 0; i < argc - 1; i++)
			fclose(merge_catalog[i]); 
		free(merge_catalog);
		exit(EXIT_FAILURE);
	}

	// -------------------------------------------------------------------------

	// Merge -------------------------------------------------------------------

	for (i = 0; i < argc - 1; i++)
		update(merge_catalog[i]);

	fwrite(inventory, sizeof(struct part), num_parts, merged_fp);

	fclose(merged_fp);
	free(merge_catalog);

	return 0;
}

int find_part(int number) {
	int i = 0;
	for (; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

bool insert(struct part cmp) {
	int pos;

	// Exception handling
	if (num_parts == MAX_PARTS) {
		fprintf(stderr, "Database got full while merging; can't add more parts.\n");
		return false;
	}

	// Rearrangement process
	if ((pos = find_part(cmp.number)) >= 0) {
		if (strcmp(cmp.name, inventory[pos].name) != 0) {
			fprintf(stderr, "Inconsistent part name issue, part number: %d\n", cmp.number);
			return false;
		}
		else
			inventory[pos].on_hand += cmp.on_hand;
	}

	else {
		for (pos = 0; pos < num_parts && inventory[pos].number < cmp.number; pos++);
		for (int shift = num_parts - 1; shift >= pos; shift--)
			inventory[shift + 1] = inventory[shift];

		// Uploading data
		inventory[pos].number = cmp.number;
		strcpy(inventory[pos].name, cmp.name);
		inventory[pos].on_hand = cmp.on_hand;

		// Increase num_parts
		num_parts++;
	}
	
	return true;
}

void update(FILE *fp) {
	struct part cmp;

	while (fread(&cmp, sizeof(cmp), 1, fp) == 1)
		if (insert(cmp) == false)
			break;

	fclose(fp);
}

