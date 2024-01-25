#include <stdio.h>

unsigned int reverse_bits(unsigned int n);

int main(void) {
	unsigned int u;
	unsigned int reverse_u;
	printf("Enter an integer: ");
	scanf("%u", &u);

	printf("Binary representation: ");
	for (int i = 8 * sizeof(unsigned int) - 1; i >= 0; i--)
		printf("%d", (u >> i) & 1);
	printf("\n");

	reverse_u = reverse_bits(u);

	printf("Binary representation of reverse bit: ");
	for (int i = 8 * sizeof(unsigned int) - 1; i >= 0; i--)
		printf("%d", (reverse_u >> i) & 1);
	printf("\n");

	return 0;
}

unsigned int reverse_bits(unsigned int n) {
	unsigned int reversal_bit = 0;
	int size = 8 * sizeof(unsigned int);
	for (int i = 0; i < size; i++)
		reversal_bit |= (n >> i & 1) << size - i - 1;

	return reversal_bit;
}

