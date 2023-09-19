/**
 * (a)
 * Show how to declare a tag named complex for a structure
 * with 2 members, real and imaginary, of type double.
 *
 * (b)
 * Use the complex tag to declare variables named c1, c2 and c3.
 *
 * (c)
 * Write a function named make_complex that stores its 2 arguments
 * (both of type double) in a complex structure, then returns the structure.
 * 
 * (d)
 * Write a function named add_complex that adds the corresponding members
 * of its arguments (both complex structures), then returns the results.
 * (another complex structure)
 **/

#include <stdio.h>


// External
struct complex {
	double real;
	double imaginary;
};

// Protoypes
struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex c1, struct complex c2);


// Main
int main(void) {
	struct complex c1, c2, c3;

	c1 = make_complex(1.0, 0.0);
	c2 = make_complex(0.0, 1.0);
	c3 = add_complex(c1, c2);

	printf("c1.real: %.1f\tc1.imaginary: %.1f\n", c1.real, c1.imaginary);
	printf("c2.real: %.1f\tc2.imaginary: %.1f\n", c2.real, c2.imaginary);
	printf("c3.real: %.1f\tc3.imaginary: %.1f\n", c3.real, c3.imaginary);

	return 0;
}

// Functions
struct complex make_complex(double real, double imaginary) {
	return (struct complex) {real, imaginary};
}

struct complex add_complex(struct complex c1, struct complex c2) {
	return (struct complex) {c1.real + c2.real, c1.imaginary + c2.imaginary};
}
