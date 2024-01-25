#include <stdio.h>
#include "stackADT.h"

#define FLUSH while (getchar() != '\n')
#define INITIAL_SIZE 5


int main (void) {
	Stack stk;
	stk = create_arr_stk(INITIAL_SIZE);

	printf("m: make_empty\n"
			"p: push\n"
			"o: pop\n"
			"k: peek\n"
			"i: information\n"
			"q: destroy and quit\n"
		  );


	for (;;) {
		static int order;
		static int push_item;
		printf("Enter process you want to do(m/p/o/k/i/q): ");
		order = getchar();
		FLUSH;

		switch (order) {
			case 'm': make_empty(stk); break;
			case 'p':
				printf("Enter an item to push: ");
				scanf("%d", &push_item);
				FLUSH;
				push(stk, push_item);
				break;
			case 'o':
				pop(stk);
				printf("Pop succeeded.\n");
				break;
			case 'i':
				printf("State:\n");
				printf("top: %2d\n", get_stk_top(stk));
				printf("size: %2d\n", get_stk_size(stk));
				print_stk(stk);
				break;
			case 'q':
				destroy(stk);
				return 0;
			default:
				printf("Invalid input, ignored.\n");
				break;
		}
	}
}


