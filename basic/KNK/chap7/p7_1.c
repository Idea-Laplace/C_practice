#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int main (void) {
	_Bool loop = TRUE;
	 while (loop) {
		char type;
		int overflow = 0;
		printf("Choose a type of integer among short(s), int(i) and longlong(l): ");
		type = getchar();
		getchar();

		switch (type) {
			case 's':
				for (short i = 1; 0 < (short) (i * i);) {
					printf("%5hd%10hd\n", i, i * i);
					overflow = ++i;
				}
				printf("In short type overflow occurs when i = %d\n", overflow);
				break;
			case 'i':
				for (int i = 1; 0 < i * i;) {
					printf("%5d%20d\n", i, i * i);
					overflow = ++i;
				}
				printf("In int type overflow occurs when i = %d\n", overflow);
				break;
			case 'l':
				for (long long i = 1; 0 < i * i;) {
					printf("%5lld%40lld\n", i, i * i);
					overflow = ++i;
				}
				printf("In short type overflow occurs when i = %d\n", overflow);
				break;
			default :
				printf("Type s, i or l\n");
				continue;
		}
		// Loop decision
		char reply;
		do {
			printf("Loop this program? (y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n================================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = FALSE; break;
				default :
					printf("Type y or n.\n");
					printf("Loop this program? (y/n): ");
					break;
			}
		} while (reply != 'y' && reply != 'n');
	 }
	 system("pause");
	 return 0;
}
