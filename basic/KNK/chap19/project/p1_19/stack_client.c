#include <stdio.h>
#include "stackADT.h"

#define FLUSH while (getchar() != '\n')

int main(void) {
	Stack stk = create();
	int order, push_item;

	printf("m: make_empty\n"
			"p: push\n"
			"o: pop\n"
			"i: get information\n"
			"q: destroy and quit\n"
		  );

	for (;;) {
		printf("Enter process you want(m/p/o/i/q): ");
		order = getchar();
		FLUSH;

		switch (order) {
			case 'm': make_empty(stk); break;
			case 'p':
				printf("Enter an item to push: ");
				push_item = getchar();
				FLUSH;
				push(stk, push_item);
				break;
			case 'o':
				pop(stk);
				printf("Pop succeeded.\n");
				break;
			case 'i':
				printf("Top: %c\n", peek(stk));
				printf("Elements:\n");
				print_stk(stk);
				break;
			case 'q':
				destroy(stk);
				return 0;
			default :
				printf("Invalid input, ignored.\n");
				break;
		}
	}
}



		

