/*
   Write a program that converts a complex number in polar coordinates 
   to Cartesian form. After the user enters the values of r and theta,
   the program will display the number in the form a + bi, where
   a = rcon$
   b = rsin$
*/

#include <math.h>
#include <stdio.h>

int main(void) {
	double norm, rad;
	double a, b;

	printf("Enter norm and radian for a complex number: ");
	scanf("%lf%lf", &norm, &rad);

	printf("You entered: %.1ge^(%.1gi)\n", norm, rad);

	a = norm * cos(rad);
	b = norm * sin(rad);

	printf("In Cartesian form: %.1g%+.1gi\n", a, b);

	return 0;
}
