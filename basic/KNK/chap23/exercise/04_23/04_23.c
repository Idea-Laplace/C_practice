#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 30

bool isidf(char *str);

int main(void) {
	char str[LEN + 1];
	printf("Type to whether the input is a valid identifier: ");
	scanf("%30s", str);
	while (getchar() != '\n');

	if (isidf(str))
		printf("%s is a valid identifier.\n", str);
	else
		printf("%s is not a valid identifier.\n", str);

	return 0;
}

bool isidf(char *str) {
	char *p = str;

	if (!isalpha(*p) && *p != '_')
		return false;
	p++;

	for (; isalnum(*p) || *p == '_'; p++);

	if (*p) return false;
	else return true;
}


