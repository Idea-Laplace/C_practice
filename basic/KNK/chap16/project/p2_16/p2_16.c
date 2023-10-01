#include <stdio.h>
#include "part.h"

#define FLUSH while (getchar() != '\n')


int main(void) {
	char code;
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		FLUSH;

		switch (code) {
			case 'i': insert(); break;
			case 's': search(); break;
			case 'u': update(); break;
			case 'p': print(); break;
			case 'q': return 0;
			default : printf("Illegal code, Try again.\n"); break;
		}
		putchar('\n');
	}
}



