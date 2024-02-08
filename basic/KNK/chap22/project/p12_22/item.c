#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define MONTH 0
#define DAY 1
#define YEAR 2

struct item_info {
	int number;
	float unit_price;
	int purchase_date[3];
	struct item_info *next;
};

struct item_info *catalog = NULL;


int find_item(int number) {
	struct item_info *p = catalog;

	for (; p != NULL; p = p->next)
		if (p->number == number)
			return number;
	return -1;
}

int insert(FILE *fp) {
	struct item_info *new_item, *prev, *cur;
	int input;
	int ch;
	if ((new_item = malloc(sizeof(*new_item))) == NULL) {
		fprintf(stderr, "Error: cannot add to list, memory is full.\n");
		exit(EXIT_FAILURE);
	}

	// Input -------------------------------------------------------------------------------
	if (fp == stdin) 
		printf("Enter item number: ");
	input = fscanf(fp, "%d", &new_item->number);

	
	if (input != 1 && input != EOF) {
		printf("Invalid item number.\n");
		if (fp == stdin)
			while (getchar() != '\n');
		return -1;
	} else if (input == EOF) return EOF;

	if (find_item(new_item->number) != -1) {
		printf("Item number %d already exists.\n", new_item->number);
		while (getchar() != '\n');
		free(new_item);
		return -2;
	}


	if (fp == stdin) 
		printf("Enter unit price($): ");
	
	input += fscanf(fp, "%*[ \r\n,]%f", &new_item->unit_price);
	if (input != 2) {
		printf("Invalid unit price.\n");
		while (getchar() != '\n');
		return -3;
	}

	if (fp == stdin) 
		printf("Enter purchase date (mm/dd/yyyy): ");
	input += fscanf(fp, "%*[ \r\n,]%2d/%2d/%4d", &new_item->purchase_date[MONTH],\
			&new_item->purchase_date[DAY], &new_item->purchase_date[YEAR]);
	if (fp == stdin)
		while ((ch = getchar()) != '\n');

	if (input != 5) {
		printf("Invalid date format.\n");
		return -4;
	}
	// -------------------------------------------------------------------------------------

	for (prev = NULL, cur = catalog;
		cur != NULL && cur->number < new_item->number;
		prev = cur, cur = cur->next);

	new_item->next = cur;
	if (prev == NULL)
		catalog = new_item;
	else
		prev->next = new_item;

	return input;
}

void erase_all(void) {
	struct item_info *cur, *next;
	cur = catalog;

	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	catalog = NULL;
}

void print(void) {
	struct item_info *p = catalog;
	printf(" Item     Unit Price($)     Purchase Date \n");
	printf("------   ---------------   ---------------\n");
	for (; p != NULL; p = p->next) {
		printf("%5d    ", p->number);
		printf("%14.2f    ", p->unit_price);
		printf("    %.2d/%.2d/%.4d\n", p->purchase_date[MONTH], p->purchase_date[DAY],\
				p->purchase_date[YEAR]);
	}
}

void save(void) {
	FILE *fp;
	struct item_info *p;
	char filename[100 + 1];
	printf("Enter filename, file of which you want to save data: ");
	scanf("%[^\n]", filename);
	while (getchar() != '\n');

	fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "Save file cannot be opened.\n");
		exit(EXIT_FAILURE);
	}

	for (p = catalog; p != NULL; p = p->next) {
		fprintf(fp, "%d,%f,%d/%d/%d\n", p->number, p->unit_price,\
			p->purchase_date[MONTH], p->purchase_date[DAY], p->purchase_date[YEAR]);
	}

	fclose(fp);
	printf("Item info save at %s.\n", filename);
}

void open(FILE *restore) {
	FILE *fp;
	if (restore == NULL) {
		char filename[100 + 1];
		printf("Enter filename to restore: ");
		scanf("%[^\n]", filename);
		while (getchar() != '\n');

		fp = fopen(filename, "r");
		if (fp == NULL) {
			printf("File %s cannot be opened.\n", filename);
			exit(EXIT_FAILURE);
		}
	}
	else fp = restore;

	erase_all();

	for (int line = 1; insert(fp) == 5; line++) {
		printf("Line %2d restored.\n", line);
	}

	if (feof(fp))
		printf("Restored from the called file.\n");
	else 
		printf("Restoration failed.\n");
	
	fclose(fp);
	return;
}
