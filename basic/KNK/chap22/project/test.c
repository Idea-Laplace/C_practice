// The program won't print the sentence below on the screen.
// Since the statement fclose(stdout);
// Related to p12_22

#include <stdio.h>

int main(void) {
	fclose(stdout);
	printf("Hello, world!\n");
	return 0;
}
