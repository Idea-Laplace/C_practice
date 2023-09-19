#include <stdio.h>
#include <stdlib.h>

#define DISP(f, x) (printf(#f"(%g) = %g\n", (x), f(x)))
#define DISP2(f, x, y) (printf(#f"(%g, %g) = %g\n", x, y, f(x, y)))


double twice(double x);
double area(double, double);
int main(void) {
	DISP(twice, 3.0);
	DISP2(area, 3.0, 3.0);

	return 0;
}

double twice(double x) {
	return 2 * x;
}

double area(double x, double y) {
	return x * y;
}

