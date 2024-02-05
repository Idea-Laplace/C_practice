#include <stdio.h>

int main(void) {
	int ch;
	int n = 0;
	while ((ch = getchar()) != EOF) {
		if (n++ % 20 == 0)
			printf("\n");
		printf("%.2x ", ch);
	}
	printf("\n");
	return 0;
}
