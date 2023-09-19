#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {

		printf("Size of char: %d\n", (int) sizeof(char));
		printf("Size of int: %d\n", (int) sizeof(int));
		printf("Size of short: %d\n", (int) sizeof(short));
		printf("Size of long: %d\n", (int) sizeof(long));
		printf("Size of long long: %d\n", (int) sizeof(long long));
		printf("Size of float: %d\n", (int) sizeof(float));
		printf("Size of double: %d\n", (int) sizeof(double));
		printf("Size of long double: %d\n", (int) sizeof(long double));

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
