#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
	int ch;
	bool empty_line = true;

	while ((ch = getchar()) != EOF) {
		if (isblank(ch))
			continue;
		else if (isspace(ch)) {
			if (empty_line)
				continue;
			else {
				putchar(ch);
				empty_line = true;
			}
		} else {
			putchar(ch);
			empty_line = false;
		}
	}
	return 0;
}

