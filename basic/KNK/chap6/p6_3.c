/****************************************************************
* Definition of the Greatest Common Divisor(GCD)                *
* The gcd of integers, say a and b, denoted by gcd(a, b)        *
* is the 'positive' integer d that satisfying the following:    *
* 1. d|a and d|b.                                               *
* 2. If c|a and c|b, then d >= c.                               *
* Here is an useful lemma:                                      *
* If a = bq + r, where q is the quotient and r is the remainder,*
* then gcd(a, b) = gcd(b, r)                                    *
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;
	int m, n, denom, num, remainder, gcd;

	while(loop){
		int reply = 0;
		printf("Enter a fraction(m/n): ");
		scanf("%d /%d", &m, &n);
		getchar();
		denom = n;
		num = m;

		if (m == 0)
			printf("In lowest terms: 0\n"); 
		else if (n == 0){
			printf("0 division error, try again.\n");
			continue;
		}
		else if (m % n == 0)
			printf("In lowest terms: %d\n", m/n);
		else{
			do{
				if (num % denom < 0){           // In C99 compiler % does not always return a nonnegative value,
					if (denom < 0)
						remainder = -denom + num % denom;  // depending on the sign of left operand.
					else
						remainder = denom + num % denom;
				}
				else
					remainder = num % denom;

				num = denom;
				denom = remainder;
			} while (remainder != 0);
			gcd = num;

			if (n < 0)
				printf("In lowest terms: %d/%d\n", -m/gcd, -n/gcd);
			else
				printf("In lowest terms: %d/%d\n", m/gcd, n/gcd);
		}

		while (reply != 'y' && reply != 'n'){
			printf("\nLoop this program?(y/n) > ");
			reply = getchar();
			getchar();

			switch(reply){
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("\nProgram terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		}
	}
	system("pause");
	return 0;
}
