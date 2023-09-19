#include <stdio.h>
#include <stdlib.h>

#define DOUBLE(x) 2*x
#define SAFE_DOUBLE(x) (2*(x))


int main(void) {
	printf("DOUBLE(1+2) is : %d\n", DOUBLE(1+2));
	printf("SAFE_DOUBLE(1+2) is : %d\n", SAFE_DOUBLE(1+2));
	printf("4/DOUBLE(2) is : %d\n", 4/DOUBLE(2));
	printf("4/SAFE_DOUBLE(2) is : %d\n", 4/SAFE_DOUBLE(2));
	return 0;
}
