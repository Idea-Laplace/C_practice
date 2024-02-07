#include <stdio.h>
#include <stdlib.h>
#include "inventory2.h"

struct part;


int main(void) {
	struct part *inventory2 = NULL;
	char reply;


	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &reply);
		while (getchar() != '\n');

		switch (reply) {
			case 'i':
				insert(&inventory2);
				break;
			case 's':
				search(inventory2);
				break;
			case 'u':
				update(inventory2);
				break;
			case 'p':
				print(inventory2);
				break;
			case 'd':
				dump(inventory2);
				break;
			case 'r':
				restore(&inventory2);
				break;
			case 'q':
				destroy(inventory2);
				printf("Process terminated.\n");
				return 0;
			default :
				printf("invalid code\n");
				break;
		}

	}
}

