#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void) {
	char s[10 + 1];
	int i = 0;
	strcpy(s, "abcd");
	putchar(TOUPPER(s[++i]));
	
	char s2[10 + 1];
	strcpy(s2, "0123");
	i = 0;
	putchar(TOUPPER(s2[++i]));
	puts("");
	return 0;
}

