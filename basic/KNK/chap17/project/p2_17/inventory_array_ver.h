#ifndef INVENTORY_ARRAY_VERSION_H
#define INVENTORY_ARRAY_VERSION_H

#define NAME_LEN 25
#define INITIAL_PARTS 10


struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};


void init();
int find_part(int number);
void insert();
void search();
void update();
void print_part();

#endif
