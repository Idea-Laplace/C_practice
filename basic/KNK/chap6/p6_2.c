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
	int m, n, remainder, gcd;

	while(loop){
		int reply = 0;
		printf("Enter 2 positive integers: ");
		scanf("%d%d", &m, &n);
		getchar();

		if (m == 0)
			printf("Greatest common divisor: %d\n", n); // By the definition if gcd, gcd(0, n) = n 
		else if (n == 0)
			printf("Greatest common divisor: %d\n", m); // Since n|n and n|0.
		else{
			do{
				if (m % n < 0){           // In C99 compiler % does not always return a nonnegative value,
					if (n < 0)
						remainder = -n + m % n;  // depending on the sign of left operand.
					else
						remainder = n + m % n;
				}
				else
					remainder = m % n;
				
				printf("m: %d, n: %d, m%%n: %d, remainder: %d\n", m, n, m%n, remainder); //Simple checking

				m = n;
				n = remainder;
			}
			while (remainder != 0);

			printf("Greatest common divisor: %d\n", m);
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
