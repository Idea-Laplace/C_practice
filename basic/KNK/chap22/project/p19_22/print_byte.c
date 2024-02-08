#include <stdio.h>
#include <stdlib.h>

#define LINE 30
int main(void) {
	int i, ch;

	i = 0;
	while ((ch = getchar()) != EOF) {
		i++;
		printf("%.2x", ch);
		i % LINE ? printf(" ") : printf("\n");
	}
	if (i % LINE) printf("\n");

	return 0;
}

