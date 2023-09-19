#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		double f, sum = 0;
		
		printf("This program sums a series of float numbers.\n");
		printf("Enter integers (0 to terminate): ");
		do {
			scanf("%lf", &f);
			sum += f;
		} while (f != 0);
		printf("The sum is: %f\n", sum);
		getchar();

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
