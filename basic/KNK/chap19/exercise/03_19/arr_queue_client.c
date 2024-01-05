#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MEMBER 30
#define SCALE 100

int main(void) {
	Queue circular_queue;

	srand((unsigned) time(NULL));
	circular_queue = create_queue();

	printf("Exit<- ");
	for (int i = 0; i < MEMBER; i++) {
		int j = rand() % SCALE;
		insert_item_queue(circular_queue, j);
		printf("%2d ", j);
	}
	printf("<-Entrance\n");

	printf("Last entranced member: %2d\n",
			check_entrance_queue(circular_queue));

	printf("First entrance member: %2d\n",
			check_exit_queue(circular_queue));

	for (int i = 0; i < MEMBER / 2; i++) {
		pop_item_queue(circular_queue);
	}


	printf("Last entranced member: %2d\n",
			check_entrance_queue(circular_queue));

	printf("First entrance member: %2d\n",
			check_exit_queue(circular_queue));

	return 0;
}


