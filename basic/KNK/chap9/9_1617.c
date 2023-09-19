#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long factorial_recursive(int n);
long long factorial(int n);

int main(void) {
	for (;;) {
		double start, end;
		int n;

		printf("Enter a number n to evaluate n!: ");
		scanf("%d", &n);
		getchar();

		start = (double) time(NULL);
		printf("Recursive version: %lld\n", factorial_recursive(n));
		end = (unsigned) time(NULL);
		printf("Runtime: %.13g\n\n", end - start);

		start = (unsigned) time(NULL);
		printf("Non-recursive version: %lld\n", factorial(n));
		end = (unsigned) time(NULL);
		printf("Runtime: %.13g\n", end - start);


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

long long factorial_recursive(int n) {
	return n == 1 ? 1 : n * factorial_recursive(n - 1);
}

long long factorial(int n) {
	long long result = 1;
	while (n > 1)
		result *= n--;

	return result;
}

