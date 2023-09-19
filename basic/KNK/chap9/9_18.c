#include <stdio.h>
#include <stdlib.h>

int gcd_mathematical(int m, int n);
int gcd_recursive(int m, int n);
int gcd_simple(int m, int n);

int main(void) {
	int m, n;
	for(;;) {
		printf("Enter 2 numbers to get the greatest common divisor of themselves[m, n]: ");
		scanf("%d ,%d", &m, &n);
		printf("G.C.D.(mathematical ver.) : %d\n", gcd_mathematical(m, n));
		printf("G.C.D.(recursive ver.) : %d\n", gcd_recursive(m, n));
		printf("G.C.D.(simple ver.) : %d\n", gcd_simple(m, n));
		getchar();

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n==============================\n"); break;
				case 'n': printf("Program terminated.\n"); goto out;
				default : printf("Type y or n.\n"); break;
			}
		}
		while (reply != 'y' && reply != 'n');
	}
	out:
	system("pause");
	return 0;
}


int gcd_mathematical(int m, int n) {
	int dividend = m, divisor = n, temp;
	if (m == 0 && n == 0) {
		printf("Error: At least either of numbers must be nonzero.\n");
		return -1;
	}

	while (divisor != 0) {
		temp = dividend;
		dividend = divisor;
		if (temp > 0)
			divisor = temp % divisor;
		else if (divisor > 0)
			divisor = divisor + temp % divisor;
		else
			divisor = -divisor + temp % divisor;
	}

	return dividend > 0 ? dividend : -dividend;
}


int gcd_recursive(int m, int n) {
	int dividend = m, divisor = n, temp;

	if (m == 0 && n == 0) {
		printf("Error: At least either of numbers must be nonzero.\n");
		return -1;
	}

	if (n == 0)
		return m > 0 ? m : -m;

	temp = dividend; dividend = divisor;
	divisor = temp % divisor;


	return gcd_recursive(dividend, divisor);
}

int gcd_simple(int m, int n) {
	int dividend = m, divisor = n, temp;

	if (m == 0 && n == 0) {
		printf("Error: At least either of numbers must be nonzero.\n");
		return -1;
	}

	while (divisor != 0) {
		temp = dividend; dividend = divisor;
		divisor = temp % divisor;
	}

	return dividend > 0 ? dividend : -dividend;
}
