#include <stdio.h>

int main(void) {
	union {
		double a;
		struct {
			char b[4];
			double c;
			int d;
		} e;
		char f[4];
	} u;

	printf("Size of u: %lu\n", sizeof u);
	return 0;
}
