/*
   Write a program that tests whether your compiler's ""(native) locale
   is the same as its "C" locale.
*/

#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *s1, *s2;

	s1 = setlocale(LC_ALL, NULL);
	assert(s1 != NULL);

	s2 = malloc(strlen(s1) + 1); // 1 for null character.
	assert(s2 != NULL);

	strcpy(s2, s1);

	s1 = setlocale(LC_ALL, "");
	if (s1 == NULL) {
		free(s2);
		assert(s1 != NULL);
	}

	printf("%s\n", s2);
	printf("%s\n", s1);

	if (strcmp(s1, s2))
		printf("False, \"C\" and \"\" are not same.\n");
	else
		printf("True, \"C\" and \"\" are same.\n");



	return 0;
}
