/*
   Write a program that displays the nth roots of unity when given
   a positive integer n. The nth roots of unity are given by the formula
   e^2PIik/n, where k is an integer between 0 and n-1.
*/

#include <complex.h>
#include <stdio.h>

#define PI 3.14159265

int main(void) {
	int n;
	double exponent;
	complex z;
	printf("Enter an integer n, order of which you want to get roots for unity.: ");
	scanf("%d", &n);

	printf("nth roots of unity:\n");
	for (int k = 0; k < n; k++) {
		exponent = 2 * PI * k / n;
		z = cexp(exponent * I);
		printf("%.2g%+.2gi  ", creal(z), cimag(z));
	}

	printf("\n");

	return 0;
}

