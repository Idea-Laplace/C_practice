#include <stdint.h>
#include <stdio.h>

int main(void) {
	union {
		uint32_t i;
		float f;
	} test;

	test.f = 36.5;

	printf("test.i = %u\n", test.i);
	printf("test.f = %f\n", test.f);

	return 0;
}

