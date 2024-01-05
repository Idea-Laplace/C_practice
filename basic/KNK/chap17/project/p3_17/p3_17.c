#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

// Global variables and Function Prototypes.
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL; /* points  to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

// NEW!! p3_17
void erase(void);

//-----------------------------------------------


// Main
int main(void) {
    char code;

    for(;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');

        switch (code) {
            case 'i': insert(); break;
			case 'e': erase(); break;
            case 's': search(); break;
            case 'u': update(); break;
            case 'p': print(); break;
            case 'q': return 0;
            default : printf("Illegal code, ignored.\n");
        }
        printf("\n");
    }
}

// Function definitions
struct part *find_part(int number) {
    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next);
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

void insert(void) {
    struct part *cur, *prev, *new_node;
    new_node = malloc(sizeof(struct part));
    
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);
	while (getchar() != '\n');

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next);

    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);  // Very important.
        return;
    }

    printf("Enter part name: ");
    readline(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
	while (getchar() != '\n');

    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
    
    new_node->next = cur;
}

void erase(void) {
	struct part *prev, *cur;
	int number;

    printf("Enter part number: ");
    scanf("%d", &number);
	while (getchar() != '\n');

    for (cur = inventory, prev = NULL;
         cur != NULL && number > cur->number;
         prev = cur, cur = cur->next);

	if (number != cur->number) {
		printf("Part not found.\n");
		return;
	}

	if (prev == NULL) {
		inventory = inventory->next;
		free(cur);
	}

	else {
		prev->next = cur->next;
		free(cur);
	}
}


void search(void) {
    int number;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);
    
    if (p == NULL)
        printf("Part not found.\n");
    else {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %2d\n", p->on_hand);
    }
}
void update(void) {
    int number, change;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);
    
    if (p == NULL) {
        printf("Part not found.\n");
        return;
    }
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
}

void print(void) {
    struct part *p;
    printf("  Part Number       Part Name         Quantity on Hand\n");
    printf("------------------------------------------------------\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d    %-25s%11d\n", p->number, p->name, p->on_hand);
}
