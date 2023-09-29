#include <stdio.h>


int main(void) {
	struct {
		double a;
		union {
			char b[4];
			double c;
			int d;
		} e;
		char f[4];
	} s;

	printf("byte: %lu\n", sizeof s);
	printf("Unit byte is 8.\n");
	return 0;
}
