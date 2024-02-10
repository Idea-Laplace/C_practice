#include <setjmp.h>
#include <stdio.h>
#include "inventory.h"

/* The jmp_buf variable env will need to be global, rather than local to main, 
   so that the function performing the longjmp will be able to supply it as an argument.
*/

jmp_buf env;

int main(void) {
	char code;

	setjmp(env);
	printf("Enter operation code: ");
	scanf(" %c", &code);
	while (getchar() != '\n');

	switch (code) {
		case 'i': insert(); break;
		case 's': search(); break;
		case 'u': update(); break;
		case 'p': print(); break;
		case 'q': printf("Process terminated.\n"); return 0;
		default : printf("Illegal code.\n"); break;
	}
	printf("\n");
	longjmp(env, 1);
}
