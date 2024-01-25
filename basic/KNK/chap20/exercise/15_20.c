#include <stdio.h>

int main(void) {
	struct {
		unsigned int flag: 1;
	} s;

	s.flag = 1;

	// From compiler to compiler, the output could be either 1 or -1.
	printf("%d\n", s.flag);
	return 0;
}


// Since the MSB of a signed integer represents sign bit.
// You need to declare flag unsigned instead of just int.

