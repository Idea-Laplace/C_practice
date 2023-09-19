#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int main (void) {
	_Bool loop = TRUE;
	while (loop) {
		int arithmetic, num;
		printf("Enter either octal or hexadecimal arithmeticber to convert into decimal one.\n");
		printf("Type 8 or 16 to determine what arithmeticber to convert into decimal one: ");
		scanf("%2d", &arithmetic);

		switch (arithmetic) {
			case 8:
				printf("Enter a nonnegative octal integer: ");
				scanf("%o", &num);
				printf("In decimal form: %d\n", num);
				break;
			case 16:
				printf("Enter a nonnegative hexadecimal integer: ");
				scanf("%x", &num);
				printf("In decimal form: %d\n", num);
				break;
			default : printf("Type 8 or 16\n"); getchar(); continue;
		}
		getchar();
		
		char reply;
		do {
			printf("Loop this program? (y/n): ");
			reply = getchar();
			getchar();
			switch (reply) {
				case 'y': printf("==================================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = FALSE; break;
				default : printf("Type 'y' or 'n'.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
