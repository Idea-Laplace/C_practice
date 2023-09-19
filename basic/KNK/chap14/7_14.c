#include <stdio.h>
#include <stdlib.h>

#define GENERIC_MAX(type) \
type type##_max(type x, type y) { \
	return x > y ? x : y;			\
}

typedef unsigned int USI;  // It is worth to remember this trick.

GENERIC_MAX(int)
GENERIC_MAX(USI)

int main(int argc, char **argv) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	USI ux = atoi(argv[1]);
	USI uy = atoi(argv[2]);
	printf("Lager value : %d\n", int_max(x, y));
	printf("Lager value : %d\n", USI_max(ux, uy));
	return 0;
}

