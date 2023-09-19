#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;
	while (loop) {
		int n;
		printf("This program prints a table of squares.\n");
		printf("Enter the number of entries in table: ");
		scanf("%d", &n);
		getchar();
		
		for (int i = 1; i <= n; ++i) {
			printf("%10d%12d\n", i, i * i);

			if (i % 24 == 0) {
				printf("Press enter to continue...\n");
				while (getchar() != '\n');
			}
		}

		// Loop decision **********************************************************
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=================================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
		// ************************************************************************
	}
	system("pause");
	return 0;
}
