#ifndef PART_H
#define PART_H

#define NAME_LEN 25
#define MAX_PARTS 100

typedef struct {
	int number;
	char name[NAME_LEN + 1];    // 1 is for the null character.
	int on_hand;
	int price;
} part;


/**
 * find_part : Looks op a part number in the inventory array.
 *             Returns the array index if the part number is
 *             found; otherwise, returns -1
 **/
int find_part(int number, part inventory[], int *num_parts);

/**
 * insert : Prompts the user for information about a new part
 *          and then inserts the part into the database. prints
 *          an error message and returns prematurely if the part
 *          already exists or the database is full.
 **/
void insert(part inventory[], int *num_parts);

/**
 * search : Prompts the user to enter a part number, then looks up
 *          the part in the database. If the part exists, prints
 *          the name and quantity on hand; if not, prints an error
 *          message.
 **/
void search(part inventory[], int *num_parts);

/**
 * update: Prompts the user to enter a part number.
 *         Prints an error message if the part doesn't exists;
 *         otherwise, prompts the user to enter change in quantity
 *         on hand and updates the database.
 **/
void update(part inventory[], int *num_parts);

/**
 * print : Prints a listing of all parts in the database.
 *         Showing the part number, part name, and quantity
 *         on hand. Parts are sorted by part number.
 **/
void print(part inventory[], int *num_parts);

#endif
