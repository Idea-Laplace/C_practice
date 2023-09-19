#include <stdio.h>
#include <stdlib.h>


int digit(int n, int k);;


int main(void) {
	for (;;) {
		int number, k;
		printf("Enter an integer: ");
		scanf("%d", &number);
		printf("Enter digit you want to get: ");
		scanf("%d", &k);
		getchar();
		printf("Digit: %d\n", digit(number, k));

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

int digit(int n, int k) {
	if (n < 0)
		n = -n;
	for (int count = 1; count < k; ++count)
		n /= 10;
	return n % 10;
}
