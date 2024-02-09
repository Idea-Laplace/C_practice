#include <math.h>
#include <stdio.h>

double round_nearest_ndigit(double x, int digit);

int main(void) {
	return 0;
}

double round_nearest_ndigit(double x, int digit) {
	double exp = pow(10, digit);

	if (x < 0.0)
		return ceil((x * exp - 0.5) / exp);
	else
		return floor((x * exp + 0.5) / exp);
}

