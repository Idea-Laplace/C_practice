/*
   Write the following function:
   
   char *vstrcat(const char *first, ...);

   All arguements of vstrcat are assumed to be strings, except for the last argument,
   which must be a null pointer(cast to char *type). The function returns a pointer
   to a dynamically allocated string containing the concatenation of the arguments.
   vstrcat should return a null pointer if not enough memory is available.

Hint: Have vstrcat go through the arguments twice: once to determine the amount of
      memory required for the returned string and one to copy the argument into the
	  string.
*/


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vstrcat(const char *first, ...);

int main(void) {
	const char *fragment[] = {"Hello! ", "Another ", "good day ", "for studying CS!"};
	char *str;

	str = vstrcat(fragment[0], fragment[1], fragment[2], fragment[3], (char *) NULL);

	printf("%s\n", str);
	return 0;
}

char *vstrcat(const char *first, ...) {
	va_list ql;
	int len = strlen(first) + 1;
	char *temp, *cat;
	va_start(ql, first);

	temp = va_arg(ql, char *);
	while (temp != NULL) {
		len += strlen(temp);
		temp = va_arg(ql, char *);
	}

	va_end(ql);

	cat = malloc(sizeof(char) * len);
	if (cat == NULL) {
		fprintf(stderr, "Can't allocate memory for concatenated string.\n");
		return NULL;
	}

	va_start(ql, first);
	strcpy(cat, first);

	temp = va_arg(ql, char *);
	while (temp != NULL) {
		strcat(cat, temp);
		temp = va_arg(ql, char *);
	}

	va_end(ql);
	return cat;
}
