#include <stdio.h>
#define DEBUG

int f1(int (*f)(int));
int f2(int i);

int main(void) {
	printf("Answer: %d\n", f1(f2));
	return 0;
}

int f1(int (*f)(int)) {
	int n = 0;
	while ((*f)(n))
		n++;
	return n;
}

int f2(int i) {
#ifdef DEBUG
	printf("input %d, output %d\n", i, i * i + i - 12);
#endif
	return i * i + i - 12;
}
