#include <stdio.h>
#include <stdlib.h>
#include "inventory_array_ver.h"


int main(void) {
	char code;
	init();

	for (;;) {
		printf("Enter a code: ");
		scanf(" %c", &code);

		switch (code) {
			case 'i': insert(); break;
			case 's': search(); break;
			case 'u': update(); break;
			case 'p': print_part(); break;
			case 'q': return 0;
			default : printf("Invalid code.\n"); break;
		}
		puts("");
	}
}

