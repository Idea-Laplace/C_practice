#include <stdio.h>

#define BYTE 8

unsigned short swap_bytes(unsigned short i);

int main(void) {
	unsigned short sh;
	printf("Enter a hexadecimal number(up to 4 digits): ");
	scanf("%hx", &sh);


	printf("Number with bytes swapped: %#hx\n", swap_bytes(sh));

	return 0;
}

unsigned short swap_bytes(unsigned short i) {
	return i >> BYTE | i << BYTE;
}
