#include <math.h>
#include <stdio.h>
#include <time.h>

#define ORDER 5

double evaluate_polynomial(double a[], int n, double x);

int main(void) {
	double coefficient[ORDER + 1];
	double x;

	for (int i = ORDER; i >= 0; i--)
		coefficient[i] = (double)(ORDER + 1 - i);

	printf("Enter a value of x: ");
	scanf("%lf", &x);

	printf("The evaluated polynomial is : %f\n", evaluate_polynomial(coefficient, ORDER, x));
		

	return 0;
}

double evaluate_polynomial(double a[], int n, double x) {
	double eval = a[n];
	for (int i = n - 1; i >= 0; i--)
		eval = fma(eval, x, a[i]); 
	return eval;
}



