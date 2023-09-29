/**
 * Repeat Exercise 3, but this time using a type named Complex.
 **/

#include <stdio.h>


// Typedef
typedef struct {
	double real;
	double imaginary;
} Complex;

// Protoypes
Complex make_complex(double real, double imaginary);
Complex add_complex(Complex c1, Complex c2);


// Main
int main(void) {
	Complex c1, c2, c3;

	c1 = make_complex(1.0, 0.0);
	c2 = make_complex(0.0, 1.0);
	c3 = add_complex(c1, c2);

	printf("c1.real: %.1f\tc1.imaginary: %.1f\n", c1.real, c1.imaginary);
	printf("c2.real: %.1f\tc2.imaginary: %.1f\n", c2.real, c2.imaginary);
	printf("c3.real: %.1f\tc3.imaginary: %.1f\n", c3.real, c3.imaginary);

	return 0;
}

// Functions
Complex make_complex(double real, double imaginary) {
	return (Complex) {real, imaginary};
}

Complex add_complex(Complex c1, Complex c2) {
	return (Complex) {c1.real + c2.real, c1.imaginary + c2.imaginary};
}
