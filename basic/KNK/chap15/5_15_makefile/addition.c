#include <stdio.h>
#include <stdbool.h>
#include "template.h"


int main(void) {
	bool loop = true;
	while (loop) {
		int i, j;
		printf("Enter 2 integers to add: ");
		scanf("%d%d", &i, &j);
		getchar();
		printf("Addtion: %d\n", i + j);
		loop_decision(&loop);
	}
	return 0;
}
