#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./stack/stack.h"

#define FLUSH while (getchar() != '\n')


int main(void) {
	struct stack test_stack = {NULL, 0};
	int value;
	int valid_input;
	int reply;

	do {
		printf("Enter process you want(p/o/w/d/e): ");
		reply = getchar();
		FLUSH;

		switch (reply) {
			case 'p':
				printf("Enter an integer you want to input: ");
				valid_input = scanf("%d", &value);
				FLUSH;
				if (!valid_input) {
					printf("Invalid input, ignored.\n");
					continue;
				}

				push(&test_stack, value);
				break;

			case 'o':
				pop(&test_stack);
				break;

			case 'w':
				print_stack(test_stack);
				break;

			case 'd':
				printf("Depth: %d\n", test_stack.depth);
				break;

			case 'e':
				break;

			default :
				printf("Invalid input, ignored.\n");
				break;
		}

	} while (reply != 'e');

	return 0;
}

