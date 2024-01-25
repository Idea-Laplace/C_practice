// Show the output produced by each of the following program fragments.
// Assume that i, j and k are unsigned short variables.

#include <stdio.h>

int main(void) {
	// From 0 bit to 15 bit.
	unsigned short i, j, k;

	// (a)
	// Arithmetic operators take precedence over bitwise operators.
	i = 8; j = 9;    // i == 0b1000, j == 0b1001
	printf("%d\n", i >> 1 + j >> 1);
	// Ans) 0, equivalent to i >> 11. Right shift on unsigned type.

	// (b)
	i = 1;
	printf("%d\n", i & -i);
	// Ans) 1, since x & 1111111111111111 = x;


	// (c)
	// & > ^ > | precedence.
	i = 2; j = 1; k = 0;
	printf("%d\n", -i & j ^ k);
	// Ans) 0, 111...110 & 000...001 == 0; 0 ^ 0 == 0;


	// (d)
	i = 7; j = 8; k = 9;
	printf("%d\n", i ^ j & k);
	// Ans) 15, 1000 & 1001 == 1000, 0111 ^ 1000 == 1111;

	return 0;
}
