#include <stdio.h>
#include <stdlib.h>


void decimal_to_binary(int n);

int main(void) {
	for (;;) {
		int n;
		printf("Enter a number to convert to a binary number: ");
		scanf("%d", &n);
		getchar();
		decimal_to_binary(n);
		printf("(2)\n");

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n==============================\n"); break;
				case 'n': printf("Program terminated.\n"); goto end;
				default : printf("Enter y or n.\n"); break;
			}
		} while (reply != 'y');
	}
	end:
	system("pause");
	return 0;
}


void decimal_to_binary(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n != 0) {
		decimal_to_binary(n / 2);
		putchar('0' + n % 2);
	}
}
