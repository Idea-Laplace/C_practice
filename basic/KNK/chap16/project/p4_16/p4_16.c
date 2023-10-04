#include <stdio.h>
#include "part.h"

#define FLUSH while (getchar() != '\n')


int main(void) {
	part inventory[MAX_PARTS];
	int num_parts = 0;
	char code;

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		FLUSH;

		switch (code) {
			case 'i': insert(inventory, &num_parts); break;
			case 's': search(inventory, &num_parts); break;
			case 'u': update(inventory, &num_parts); break;
			case 'p': print(inventory, &num_parts); break;
			case 'q': return 0;
			default : printf("Illegal code, Try again.\n"); break;
		}
		putchar('\n');
	}
}



