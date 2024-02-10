// Write a call of memset that replaces the last n characters in a null-
// -terminated string s with ! characters.

#include <string.h>
#include <stdio.h>
int main(void) {
	char s[14] = "Hello, world!";

	printf("%s\n", s);

	int n = 5;
	memset(s + strlen(s) - n, '!', n);

	printf("%s\n", s);
	return 0;
}
