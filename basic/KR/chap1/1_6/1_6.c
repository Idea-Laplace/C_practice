// Verify that the expression getchar() != EOF is 0 or 1
#include <stdio.h>

int main(void) {
	int c;

	// Omit parentheses around c = getchar() intentionally.
	while (c = getchar() != EOF)
		printf("%d", c);
	// Print EOF
	printf("%d\n", c);
	return 0;
}
