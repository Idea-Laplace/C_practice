#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double triangle_area(double base, double height);

int main(void) {
	bool loop = true;
	while (loop) {
		float base, height;

		printf("Enter length of base of a triangle: ");
		scanf("%f", &base);
		printf("Enter length of height of a triangle: ");
		scanf("%f", &height);
		printf("Area: %g\n", triangle_area(base, height));
		getchar();

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n==============================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		}
		while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}

double triangle_area(double base, double height) {
	return 0.5 * base * height;
}
