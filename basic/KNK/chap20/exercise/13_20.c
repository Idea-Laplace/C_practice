/*
If n is an unsigned int variable, what effect doees the following statement
have on the bits in n?

n &= n - 1;

if n is odd, then n &= n - 1 make n n-1.
if n is even, it would find the least 1
and clear 1 and all trailing bits.

To sum up, n &= n - 1 makes n clear the smallest 1 bit.
*/

#include <stdio.h>


int main(void) {
	unsigned u;
	printf("Enter a nonnegative integer: ");
	scanf("%u", &u);

	while (u > 0) {
		for (int i = 31; i >= 0; i--)
			printf("%d", u >> i & 1);
		printf("\n");

		u &= u - 1;
	}

	return 0;
}

