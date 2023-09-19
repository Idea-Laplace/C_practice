#include <stdio.h>
#include <stdlib.h>


int polynomial(int x);

int main(void) {
	for (;;) {
		int x;
		printf("Enter an integer to evaluate 3x^5+2x^4-5x^3-x^2+7x-6: ");
		scanf("%d", &x);
		getchar();

		printf("Value: %d\n", polynomial(x));

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


int polynomial(int x) {
	return ((((3*x +2) * x - 5) * x - 1) * x + 7) * x - 6;
}
