#include <stdio.h>

union IEEE_float {
	float value;
	unsigned int i_value;
	struct {
		unsigned int fraction : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} bit_field;
};

int main(void) {
	union IEEE_float test;
	test.bit_field.fraction = 0;
	test.bit_field.exponent = 128;
	test.bit_field.sign = 1;

	printf("%f\n", test.value);

	test.value = 36.5;

	printf("Now the value is 36.5.\n");
	printf("i_value: %u\n", test.i_value);
	printf("sign: %d\n", test.bit_field.sign);
	printf("exponent: %d\n", test.bit_field.exponent);
	printf("fraction: %d\n", test.bit_field.fraction);


	for (int i = 31; i >= 0; i--) {
		printf("%d", test.i_value >> i & 1);
		if (i % 8 == 0)
			printf(" ");
	}
	printf("\n");

	unsigned char *p = (unsigned char *) &test.value;
	for (int i = 0; i < 4; i++) {
		printf("%.2x ", *(p + i));
	}
	printf("\n");

	return 0;
}
