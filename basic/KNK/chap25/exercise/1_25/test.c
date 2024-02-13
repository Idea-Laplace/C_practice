#include <locale.h>
#include <stdio.h>

int main(void) {
	char *s = setlocale(LC_ALL, NULL);
	printf("%s\n", s);
	return 0;
}
