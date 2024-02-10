#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "additional_string.h"

char *strup(char *s) {
	char *copy;
	copy = malloc(1 * sizeof(strlen(s) + 1));

	if (copy == NULL) {
		fprintf(stderr, "Error: Not enough memory to copy the  given string %s.\n", s);
		return NULL;
	}

	strncpy(copy, s, strlen(s) + 1);
	return copy;
}

int stricmp(char *s1, char *s2) {
	while (*s1 || *s2) {
		if (tolower(*s1) == tolower(*s2))
			s1++, s2++;
		else
			return tolower(*s1) - tolower(*s2);
	}

	return 0;
}

char *strlwr(char *s) {
	char *p = s;
	while (*p) {
		if (isupper(*p))
			*p = tolower(*p);
		p++;
	}
	return s;
}

char *strrev(char *s) {
	char *start = s;
	char *end = s + strlen(s) - 1;
	char temp;

	while (start < end) {
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
	return s;
}

char *strset(char *s, char ch) {
	memset(s, ch, strlen(s));
	return s;
}
