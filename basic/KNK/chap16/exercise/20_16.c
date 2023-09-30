#include <stdio.h>


int main(void) {
	enum {NORTH, SOUTH, EAST, WEST} direction;
	int x = 0, y = 0;

	printf("Enter a direction by typing 0 ~ 3: ");
	scanf("%d", &direction);

	switch (direction) {
		case NORTH: --y; break;
		case SOUTH: ++y; break;
		case EAST: ++x; break;
		case WEST: --x; break;
		default: break;
	}

	printf("x: %d\t""y: %d\n", x, y);
	return 0;
}
