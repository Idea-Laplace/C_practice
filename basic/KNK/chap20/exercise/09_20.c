// (a) Write the following function:
// int count_ones(unsigned char ch);
// count_ones should return the number of 1 bit in ch.
// (b) Write the function in part (a) without using loop.


#include <stdio.h>
#define BYTE 8

typedef unsigned char UNIT;

int count_ones(UNIT ch);

int main(void) {
	UNIT i;
	printf("Enter an integer(0~255): ");
	scanf("%hhd", &i);

	printf("Binary representation: ");
	for (int k = 0; k < BYTE; k++)
		printf("%d", i >> BYTE - 1 - k & 1);
	printf("\n");

	printf("Number of 1 bit: %d\n", count_ones(i));

	return 0;
}


int count_ones(UNIT ch) {

	if (ch == 0)
		return 0;
	if (ch == 1)
		return 1;
	
	return (ch & 1) + count_ones(ch >> 1);
}


