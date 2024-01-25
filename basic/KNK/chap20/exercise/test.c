#include <stdint.h>
#include <stdio.h>

#define BYTE_LEN 8

char *bit_expression(uint8_t k, char *result) {
	for (int j = 0; j < BYTE_LEN; j++) {
		if (k & (1 << j))
			result[BYTE_LEN - 1 - j] = '1'; 
		else
			result[BYTE_LEN - 1 - j] = '0';
	}

	result[BYTE_LEN] = '\0';

	return result;
}

int main(void) {
	uint8_t i;
	char operand_1[BYTE_LEN + 1];
	char operand_2[BYTE_LEN + 1];
	char result[BYTE_LEN + 1];
	for (i = 0; i < 100; i++) 
		printf (" %2d & %2d = %2d\n", i, -i, i & -i);

	printf("\n");

	for (i = 0; i < 100; i++) 
		printf (" %s & %s = %s\n", bit_expression(i, operand_1),\
				bit_expression(-i, operand_2), bit_expression((i & -i), result));

	return 0;
}
