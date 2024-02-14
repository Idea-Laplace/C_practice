#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int smpl_printf(const char * restrict format, ...);

int main(void) {
	char *s = "Test string %d, %f, %c, %s and %d.";

	printf("smpl_printf version:\n");
	smpl_printf(s, 5, 3);
	printf("\n");
	printf("printf version:\n");
	printf(s, 5, 3.14, 'c', "Hello", 3);
	printf("\n");
	return 0;
}

int smpl_printf(const char * restrict format, ...) {
	const char *cur;
	int count = 0, i, power;

	va_list fl;
	va_start(fl, format);

	for (cur = format; *cur != '\0'; cur++) {
		if (*cur != '%') {
			putchar(*cur);
			count++;
			continue;
		} 

		if (*++cur == 'd') {
	
			i = va_arg(fl, int);

			// This condition cannot handle 2^31.
			if (i < 0) {
				putchar('-');
				i = - i;
				count++;
			} 

			for (power = 10; i / power; power *= 10);
			for (power /= 10; power != 0; i %= power, power /= 10) {
				putchar ('0' + i / power);
				count++;
			}
		}
	}
	va_end(fl);

	return count;
}
