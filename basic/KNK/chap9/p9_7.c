#include <stdio.h>
#include <stdlib.h>


int power(int x, int n);

int main(void) {
	int x, n;
	for (;;) {
		printf("Enter 2 integers x, n to evaluate power (x^n form): ");
		scanf("%d ^%d", &x, &n);
		getchar();
		printf("%d^%d = %d\n", x, n, power(x, n));

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


int power(int x, int n) {
	if (n == 0)
		return 1;
	else
		return n % 2 ? x * power(x, n - 1) : power(x, n / 2) * power(x, n / 2);
}
