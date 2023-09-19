#include <stdio.h>
#include <ctype.h>
#include "template.h"
#include "read.h"

#define DECO

void loop_decision(bool *loop) {
	int reply;
	char deco[MAX_LINE_LEN + 2];
	int len = 1;
#ifdef DECO
	printf("Input decoration char for new process line separator: ");
	len = read_line(deco, MAX_LINE_LEN);
#endif

	do {
		printf("Loop this process?(y/n): ");
		reply = toupper(getchar());
		while (getchar() != '\n'); // Flush remaining charaters.

		switch (reply) {
			case 'Y':
				printf("\n");
				for (int i = 0; i < (40 / len) + 1; i++)
					printf("%s", deco);
				printf("\n");
				break;
			case 'N':
				printf("\n");
				for (int i = 0; i < 40 / len; i++)
					printf("%s", deco);
				printf("\n");
				printf("Process terminated.\n");
				*loop = false;
				break;
			default :
				printf("Type y[Y] or n[N] on the first input.\n");
				break;
		}
	} while (reply != 'Y' && reply != 'N');
}
