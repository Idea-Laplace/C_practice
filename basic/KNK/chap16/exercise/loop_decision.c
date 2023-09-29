#include <stdbool.h>
#include <ctype.h>
#include "loop_decision.h"


void loop_decision(bool *loop) {
	int reply;
	
	do {
		printf("Loop this process?(y/n): ");
		reply = toupper(getchar());
		while (getchar() != '\n');

		switch (reply) {
			case 'Y':
				printf("\n====================================\n");
				break;
			case 'N':
				printf("\n====================================\n");
				printf("Process terminated.\n");
				*loop = false;
				break;
			default:
				printf("Type y[Y] or n[N] on the first input.\n");
				break;
		}
	} while (reply != 'Y' && reply != 'N');
}


