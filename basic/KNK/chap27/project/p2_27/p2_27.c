/*
   Write a program that converts a complex number in Cartesian coordinates
   to polar form. The user will enter a and b (the real and imaginary parts
   of the number); the program will display the valus of r and theta.
*/


#include <complex.h>
#include <stdio.h>

int main(void) {
	complex z;
	double rad, norm;
	double a, b;

	printf("Enter real part and imaginary part of a complex number: ");
	scanf("%lf%lf", &a, &b);
	z = a + b * I;

	printf("You entered %.1g%+.1gi\n", a, b);

	norm = cabs(z);
	rad = carg(z);

	printf("In polar form: (%f, %f)\n", norm, rad);

	return 0;
}

