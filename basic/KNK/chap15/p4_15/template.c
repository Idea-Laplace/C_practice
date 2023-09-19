#include <stdio.h>
#include <ctype.h>
#include "template.h"

void loop_decision(bool *loop) {
	int reply;

	do {
		printf("Loop this program?(y/n): ");
		reply = toupper(getchar());
		while (getchar() != '\n'); // Flush remaining charaters.

		switch (reply) {
			case 'Y':
				printf("\n====================================\n");
				break;
			case 'N':
				printf("\n====================================\n");
				printf("Program terminated.\n");
				*loop = false;
				break;
			default :
				printf("Type y[Y] or n[N] on the first input.\n");
				break;
		}
	} while (reply != 'Y' && reply != 'N');
}
