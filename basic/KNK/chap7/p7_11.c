#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		char initial, ch;
		printf("Enter a first and last name: ");
		scanf("%c", &initial);
		while (getchar() != ' ');
		while ((ch = getchar()) != '\n') {
			if (ch != ' ' && ch != '\t')
				printf("%c", ch);
		}
		printf(", %c\n", initial);


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
