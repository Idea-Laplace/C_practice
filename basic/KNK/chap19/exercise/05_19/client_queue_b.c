#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define ELEMENTS 20


int main(void) {
	Queue qu;

	qu = create_queue();

	srand((unsigned) time(NULL));

	printf("Enqueue Process\n");
	for (int i = 0; i < ELEMENTS; i++) {
		insert_item_queue(qu, rand() % 100);
		print_qu(qu);
	}

	printf("\nDequeue Process\n");
	for (int i = 0; i < ELEMENTS / 2; i++) {
		pop_item_queue(qu);
		print_qu(qu);
	}

	return 0;
}







