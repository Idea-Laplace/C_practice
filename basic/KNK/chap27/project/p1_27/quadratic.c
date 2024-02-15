/* Finds the roots of the equation 5x**2 + 2x + 1 = 0 */

/* 
   project 1, chapter 27
   Make the following modification to the quadratic.c program

   (a) Have the user enter the codfficients of the polynomial
       (the values of the variables a, b and c)
   (b) Have the program test the dicriminant before displaying
   the values of the roots. If the discriminant is negative,
   have the program display the roots in the same way as before.
   if it's nonnegative, have the program display the roots as
   real numbers(without an imaginary part).

   (c) Modify the program so that it displays a complex number with
   a negative imaginary part as a -bi instead of a +-bi.
*/


#include <complex.h>
#include <math.h>
#include <stdio.h>

int main(void) {
	double a, b, c;
	double discriminant;
	double complex discriminate_sqrt;
	double complex root1; 
	double complex root2;
	
	printf("Enter coefficients for a quadratic equation (a b c): ");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (fabs(a - 0.0) < 0.0000000000000001) {
		printf("The highest order coefficient should be nonzero.\n");
		return 0;
	}

	printf("Your equation is: %+.1fx^2%+.1fx%+.1f = 0\n", a, b, c);

	discriminant = b * b - 4 * a * c;

	if (discriminant == 0)
		printf("root = %g\n", -b / (2 * a));
	else if (discriminant > 0) {
		printf("root1 = %g\n", (-b + sqrt(discriminant)) / (2 * a));
		printf("root2 = %g\n", (-b - sqrt(discriminant)) / (2 * a));
	} else {
		discriminate_sqrt = csqrt(b * b - 4 * a * c);

		root1 = (-b + discriminate_sqrt) / (2 * a);
		root2 = (-b - discriminate_sqrt) / (2 * a);

		printf("root1 = %.2g%+.2gi\n", creal(root1), cimag(root1));
		printf("root2 = %.2g%+.2gi\n", creal(root2), cimag(root2));
	}

	return 0;
}
