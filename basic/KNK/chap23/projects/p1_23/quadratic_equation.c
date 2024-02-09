#include <math.h>
#include <stdio.h>


int main(void) {
	double a, b, c, x, x2;

	for (;;) {
		printf("Enter coefficient value for x^2: ");
		scanf("%lf", &a);

		if (fpclassify(a) == FP_ZERO) {
			printf("The leading coefficient must be nonzero.\n");
			continue;
		} 

		while (getchar() != '\n');
		break;
	}

	printf("Enter coefficient value for x: ");
	scanf("%lf", &b);
	while (getchar() != '\n');

	printf("Enter coefficient value for constant: ");
	scanf("%lf", &c);
	while (getchar() != '\n');

	x = -fma(4*a, c, -b * b);
	x2 = -fma(4*a, c, -b * b);
	if (x < 0)
		printf("The roots are complex number.\n");
	else if (fpclassify(x) == FP_ZERO)
		printf("The root is %f\n", -b / (2 * a));
	else {
		x = (-b + sqrt(x)) / (2 * a);
		x2 = (-b - sqrt(x2))/ (2 * a);
		printf("The roots are %f or %f.\n", x, x2);
	}

	return 0;
}
