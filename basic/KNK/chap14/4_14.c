#include <stdio.h>
#include <stdlib.h>

#define AVG(x, y) (x + y) / 2
#define AREA(x, y) (x)*(y)

#define SAFE_AVG(x, y) (((x) + (y)) / 2)
#define SAFE_AREA(x, y) ((x)*(y))


int main(int argc, char **argv) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	printf("8/AVG(%d, %d) is %d,\n", x, y, 8/AVG(x, y));
	printf("8/SAFE_AVG(%d, %d) is %d,\n", x, y, 8/SAFE_AVG(x, y));
	printf("8/AREA(%d, %d) is %d,\n", x, y, 8/AREA(x, y));
	printf("8/SAFE_AREA(%d, %d) is %d,\n", x, y, 8/SAFE_AREA(x, y));
	return 0;
}

