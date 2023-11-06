#ifndef INVENTORY_H
#define INVENTORY_H

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part *next;
};

struct part *find_part(struct part *inventory, int number);
void insert(struct part **inventory_address);
void search(struct part *inventory);
void update(struct part *inventory);
int compare_part(const void *p, const void *q);
void print_part(struct part *inventory);

#endif
