#include <stdio.h>
#include <string.h>
#include "additional_string.h"


int main(void) {
	char str[14] = "Hello, world!";
	char *str2;

	printf("str: %s\n", str);
	puts("");

	str2 = strup(str);
	printf("After str2 = strup(str)\n");
	printf("str2: %s\n", str2);
	puts("");

	strlwr(str2);
	printf("After strlwr(str2)\n");
	printf("str2: %s\n", str2);
	puts("");

	printf("strcmp(str, str2): str %c str2\n", strcmp(str, str2) > 0 ? '>' : '<');
	printf("stricmp(str, str2): str %s str\n", stricmp(str, str2) ? "!=" : "==");

	puts("");
	printf("str2: %s\n", str2);

	puts("");
	strrev(str2);
	printf("After strrev(str2)\n");
	printf("str2: %s\n", str2);
	puts("");

	strset(str2, '!');
	printf("After strset(str2, '!')\n");
	printf("str2: %s\n", str2);
	puts("");

	return 0;
}





