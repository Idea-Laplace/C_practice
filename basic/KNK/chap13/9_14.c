#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20
#define NEWLINE putchar('\n');

int main(void){
	char str_1[LEN + 1];
	char str_2[LEN + 1];

	strcpy(str_1, "Computer");
	char *p = str_1;
	while (*p)
		putchar(*p++);
	NEWLINE
	printf("strlen(str_1): %d ", strlen(str_1));
	NEWLINE
	strcpy(str_2, "Science");
	if (strcmp(str_1, str_2) < 0)
		strcat(str_1, str_2);
	else
		strcat(str_2, str_1);
	p = str_1;
	while (*p)
		putchar(*p++);
	NEWLINE
	printf("strlen(str_1): %d ", strlen(str_1));
	NEWLINE
	str_1[strlen(str_1) - 6] = 0;

	p = str_1;
	while (*p)
		putchar(*p++);
	NEWLINE
	printf("strlen(str_1): %d ", strlen(str_1));
	NEWLINE

	system("pause");
	return 0;
}
