#include <stdio.h>

int f(int i) {
	static int j = 0;
	return i * j++;
}

int main(void) {
	for (int i = 0; i < 6; i++)
		printf("f(10) = %2d\n", f(10));

	return 0;
}
