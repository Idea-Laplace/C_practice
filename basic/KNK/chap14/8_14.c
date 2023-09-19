#include <stdio.h>

#define STR(x) #x
#define STR_R(x) STR(x)
#define LINE_FILE "Line " STR_R(__LINE__) " of file " __FILE__


int main(void) {
	const char *s = LINE_FILE;
	puts(s);
	return 0;
}
