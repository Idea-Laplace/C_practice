#include <stdio.h>

int main(void) {
	int ch = 'a';
	printf("The putc series return what it prints.\n\n");

	printf("%d \n", fputc(ch, stdout));
	printf("%d \n", putc(ch, stdout));
	printf("%d \n", putchar(ch));


	printf("The printf function returns the length of string it prints.\n");
	printf("%d \n", printf("Hello, world!"));
	printf("The puts function always suffix \\n at end of the string and count it\n");
	printf("%d \n", puts("Hello, world!"));
	printf("The fputs function returns EOF when an error happen, otherwise returns nonnegative value\n");
	printf("%d \n", fputs("Hello, world!", stdout));

	return 0;
}

