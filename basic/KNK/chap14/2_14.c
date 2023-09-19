#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define NELEMS(arr) ((int) sizeof(arr) / sizeof (*arr))

void loop_decision(bool *loop);

int main(void) {
	bool loop = true;
	srand((unsigned) time(NULL));
	while (loop) {
		int array[rand() % 100 + 1];
		printf("Random array length: %d\n", NELEMS(array));

		loop_decision(&loop);
	}
	return 0;
}

void loop_decision(bool *loop) {
	int reply;
	do {
		printf("Loop this program?(y/n): ");
		reply = toupper(getchar());
		while (getchar() != '\n');
		switch (reply) {
			case 'Y':
				printf("\n=======================================\n");
				break;
			case 'N':
				printf("\n=======================================\n");
				printf("Program terminated.\n");
				*loop = false;
				break;
			default :
				printf("Type y[y] or n[N] on the first input.\n");
				break;
		}
	} while (reply != 'Y' && reply != 'N');
}

