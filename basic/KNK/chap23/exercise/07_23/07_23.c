/*
   Section 23.6 explains how to call strchr repeatedly to locate all
   occurrences of a character within a string. Is it possible to lo-
   -cate all occurrences in reverse order by calling strrchr repeatedly?
*/

// Only if the string is neither a string literal nor const char *;

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[14] = "Hello, world!";
	char *p;

	p = strchr(str, 'l');
	do {
		printf("Address for 'l': %p\n", p);
		p = strchr(p + 1, 'l');
	} while (p != NULL);

	printf("\n");

	p = strrchr(str, 'l');
	do {
		printf("Address for 'l': %p\n", p);
		*p = '\0';
		p = strrchr(str, 'l');
	} while (p != NULL);

	return 0;
}
	

