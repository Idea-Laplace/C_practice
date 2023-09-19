#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

int main(void){
	char str[LEN + 1];
	char *p = str;
	strcpy(str, "tire-bouchaon");
	while (*p)
		putchar(*p++);
	putchar('\n');
	p = str;

	strcpy(&str[4], "d-or-wi");
	while (*p)
		putchar(*p++);
	putchar('\n');
	p = str;

	strcat(str, "red?");
	while (*p)
		putchar(*p++);
	putchar('\n');

	system("pause");
	return 0;
}


