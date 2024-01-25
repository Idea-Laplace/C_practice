/*
	The following function supposedly combines two bytes to form an unsigned
	short integers. Explain why the statement doesn't work and show how to fix it.

	unsigned short create_short(unsigned char high_byte,\
								unsigned char low_byte) {
		return high_byte << 8 + low_byte;
	}

	binary + takes precedence over <<, so we must parenthese << term.
	(high_byte << 8) + low_byte.

	so, the fixed version would be:


	unsigned short create_short(unsigned char high_byte,\
								unsigned char low_byte) {
		return (high_byte << 8) + low_byte;
	}

	You could be curious how high_byte << 8 works without casting unsigned short,
	In expression, any integer type smaller than int automatically casted into int.
	Even though there are no int types. in expression, high_byte is treated as int.
	referred to as 'integral conversion'
*/

#include <stdio.h>

typedef unsigned char UNIT;
typedef unsigned short WORD;

WORD create_short(UNIT high_byte, UNIT low_byte);

int main(void) {
	UNIT high_byte, low_byte;

	printf("Enter an integer for high byte in hex(0 ~ ff): ");
	scanf("%hhx", &high_byte);
	printf("Enter an integer for low byte in hex(0 ~ ff): ");
	scanf("%hhx", &low_byte);

	printf("Merged value in hex: %x\n", create_short(high_byte, low_byte));

	return 0;
}

WORD create_short(UNIT high_byte, UNIT low_byte) {
	return (high_byte << 8) + low_byte;
}
