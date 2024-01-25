#include <stdio.h>

#define BYTE 8

int toggle_n_bit(int i, unsigned int bit, size_t size);

int main(void) {
	int i;
	int bit;
	printf("Enter an integer: ");
	scanf("%d", &i);

	printf("Enter the bit you want to toggle: ");
	scanf("%d", &bit);

	printf("Binary representation(least 8 significant bits): ");

	for (int j = 0; j < BYTE; j++)
		printf("%d", (i >> BYTE - 1 - j) & 1);
	printf("\n");

	i = toggle_n_bit(i, bit, BYTE * sizeof(i));

	printf("Binary representation(least significant 8 bits): ");

	for (int j = 0; j < BYTE; j++)
		printf("%d", (i >> BYTE - 1 - j) & 1);
	printf("\n");

	return 0;
}

int toggle_n_bit(int i, unsigned int bit, size_t size) {
	if (bit >= size) {
		printf("Input parameter 'bit' is too large, scaled to the size of int.\n");
		bit %= size;
	}

	i &= ~(1 << bit);

	return i;
}

