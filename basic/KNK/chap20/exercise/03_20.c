#include <stdio.h>

#define CHANGE(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))

int main(void) {
	int x, y;

	printf("Enter an integer for x: ");
	scanf("%d", &x);
	printf("Enter an integer for y: ");
	scanf("%d", &y);

	printf("x = %d, y = %d\n", x, y);
	CHANGE(x, y);
	printf("x = %d, y = %d\n", x, y);

	CHANGE(x, x);
	printf("x = %d\n", x);

	return 0;
}


/*
   x ^= y,   Now x is x ^ y;
   y ^= x,   Now y is y ^ (x ^ y) = x ^ y ^ y = x ^ 0 = x;
   x ^= y,   Now x is (x ^ y) ^ x = (x ^ x) ^ y = 0 ^ y = y;

   Since XOR operator(^) is both associative and commutative,
   The preceding flow make sense.
   Also, Note that x ^ 0 = x, x ^ 1 = ~x, where x is an arbitary single bit.
*/

/*
   Be aware if CHANGE(x, x), It would return 0 rather than x itself.
   It is because x ^= x = 0.
*/
