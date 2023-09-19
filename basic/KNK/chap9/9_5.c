#include <stdio.h>
#include <stdlib.h>


int digit(int);


int main(void) {
	for (;;) {
		int number;
		printf("Enter an integer: ");
		scanf("%d", &number);
		getchar();
		printf("Digit: %d\n", digit(number));

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

int digit(int n) {
	int count = 1;
	if (n < 0)
		n = -n;
	while (n > 9) {
		n /= 10;
		++count;
	}
	return count;
}
