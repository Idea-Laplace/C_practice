#include <stdio.h>
#include <stdlib.h>

int main(void) {
	struct point { int x, y; };
	struct rectangle {
		struct point upper_left, lower_right;
	};
	struct rectangle *p;

	p = (struct rectangle *) malloc(sizeof(struct rectangle));
	p -> upper_left.x = 10;
	p -> upper_left.y = 25;
	p -> lower_right.x = 20;
	p-> lower_right.y = 15;


	printf("p -> upper_left: (%d, %d)\n", p -> upper_left.x, p -> upper_left.y);
	printf("p -> lower_right: (%d, %d)\n", p -> lower_right.x, p -> lower_right.y);

	free(p);

	return 0;
}
	
