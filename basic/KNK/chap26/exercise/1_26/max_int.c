#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

int max_int(int n, ...);

int main(void) {
	int ran_i[LEN];

	srand((unsigned) time(NULL));
	for (int i = 0; i < LEN; i++) {
		ran_i[i] = rand() % 20 + 1;
		printf("%d ", ran_i[i]);
	}
	puts("");

	printf("Max: %d\n", max_int(ran_i[0], ran_i[1], ran_i[2], ran_i[3], ran_i[4], ran_i[5], ran_i[6],
								ran_i[7], ran_i[8], ran_i[9], 0));

	return 0;
}
	
int max_int(int n, ...) {
	va_list vl;
	int current, max = n;
	
	va_start(vl, n);

	do {
		current = va_arg(vl, int);
		if (current > max)
			max = current;
	} while (current != 0);

	va_end(vl);

	return max;
}
