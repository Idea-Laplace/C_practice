// Performs XOR encryption
// Use by < tool.

#include <stdio.h>
#include <ctype.h>

#define KEY '&'

int main(void) {
	int origin_char, new_char;

	while ((origin_char = getchar()) != EOF) {
		new_char = origin_char ^ KEY;
		if (isprint(origin_char) && isprint(new_char))
			putchar(new_char);
		else
			putchar(origin_char);
	}

	return 0;
}
