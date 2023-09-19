#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	bool loop = true;

	while (loop) {
		int num1, denom1, num2, denom2;
		int num, denom, gcd;
		char operator;

		printf("Enter 2 fractions separated by an arithmetic operator sign: ");
		scanf("%d /%d %c%d /%d", &num1, &denom1, &operator, &num2, &denom2);
		getchar();

		switch (operator) {
			case '+':
				num = num1 * denom2 + num2 * denom1;
				denom = denom1 * denom2;
				break;
			case '-':
				num = num1 * denom2 - num2 * denom1;
				denom = denom1 * denom2;
				break;
			case '*': case 'x':
				num = num1 * num2;
				denom = denom1 * denom2;
				break;
			case '/':
				num = num1 * denom2;
				denom = denom1 * num2;
				break;
			default : printf("You entered wrong operator, try again.\n"); continue;
		}

		if (denom == 0) {
			printf("Zero division error, try other case.\n");
			continue;
		}
		else {
			int divisor = denom, dividend = num, temp;

			while (divisor) {
				if (dividend >= 0) {
					temp = dividend;
					dividend = divisor;
					divisor = temp % divisor;
				}
				else if (divisor < 0) {
					temp = dividend;
					dividend = divisor;
					divisor = - divisor + temp % divisor;
				}
				else {
					temp = dividend;
					dividend = divisor;
					divisor += temp % divisor;
				}
			}
			gcd = dividend;
		}

		num /= gcd; denom /= gcd;
	
		if (denom < 0) {
			num = - num; denom = - denom;
		}

		if (denom == 1)
			printf("The sum is %d\n", num);
		else
			printf("The sum is %d/%d\n", num, denom);

		// Loop decision
		char reply;
		do {
			printf("Loop this program? (y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n===================================\n"); break;
				case 'n': printf("Program terminated.\n"); loop  = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
    system("pause");
    return 0;
}
