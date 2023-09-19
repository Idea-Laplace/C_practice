#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHECK(x, y, n)	\
(x) > 0 && (x) < (n) && (y) > 0 && (y) < (n) ? 1 : 0

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MEDIAN(x, y, z)	\
MIN(MAX(x, y), z)

#define POLYNOMIAL(x)	\
((x)*((x)*((x)*((x)*(3*(x) + 2) - 5) - 1) + 7) - 6)


int main(int argc, char **argv) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int z = atoi(argv[3]);

	printf("CHECK(%d, %d, %d): %d\n", x, y, z, CHECK(x, y, z));
	printf("MEDIAN(%d, %d, %d): %d\n", x, y, z, MEDIAN(x, y, z));
	printf("POLYNOMIAL(%d): %d\n", x, POLYNOMIAL(x));
	return 0;
}



