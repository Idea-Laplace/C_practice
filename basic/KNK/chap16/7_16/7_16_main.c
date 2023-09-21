#include <stdio.h>
#include "fraction.h"


int main(void) {
	fraction q1, q2, temp;

	for (;;) {
		printf("Enter two frations [a/b c/d]: ");
		if (scanf("%d /%d %d /%d",\
			&(q1.numerator), &(q1.denominator), &(q2.numerator), &(q2.denominator)) != 4) {
			printf("Invalid input, ignored.\n");
			while (getchar() != '\n');
			continue;
		}

		break;
	}

	temp = add_fraction(&q1, &q2);
	printf("Addition: %d/%d\n", temp.numerator, temp.denominator);

	temp = subtract_fraction(&q1, &q2);
	printf("Subtraction: %d/%d\n", temp.numerator, temp.denominator);

	temp = multiply_fraction(&q1, &q2);
	printf("Multiplication: %d/%d\n", temp.numerator, temp.denominator);

	temp = divide_fraction(&q1, &q2);
	printf("Division: %d/%d\n", temp.numerator, temp.denominator);
	
	return 0;
}

			


