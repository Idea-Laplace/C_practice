#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define INITIAL 1
#define EPSILON 0.000001

int main (void) {
	bool loop = true;

	while (loop) {
		double square, root, temp = INITIAL;
		printf("Enter a positive number: ");
		scanf("%lf", &square);
		getchar();

		root = 0.5 * (temp + square/temp);
		while (fabs(root - temp) > EPSILON) {
			temp = root;
			root = 0.5 * (temp + square/temp);
		}
		printf("Square root: %g\n", root);

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
