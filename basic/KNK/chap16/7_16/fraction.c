#include <stdio.h>
#include "fraction.h"

_Bool zero_division_error_fraction(fraction *quotient) {
	if ((*quotient).denominator == 0)
		return 1;
	return 0;
}

void reduce_to_lowest(fraction *quotient) {
	// Check 0 division error
	if (zero_division_error_fraction(quotient)) {
		printf("Zero division error, process ignored.\n");
		return;
	}

	// G.C.D. algorithm
	int dividend = (*quotient).numerator;
	int divisor = (*quotient).denominator;
	int remains = dividend % divisor;

	while (remains) {
		dividend = divisor;
		divisor = remains;
		remains = dividend % divisor;
	}

	divisor = (divisor > 0 ? divisor : -divisor);

	(*quotient).numerator /= divisor;
	(*quotient).denominator /= divisor;

}
	
fraction add_fraction(fraction *q1, fraction *q2) {
	// Check 0 division error
	if (zero_division_error_fraction(q1) || zero_division_error_fraction(q2)) {
		printf("Zero division error, process ignored.\n");
		return (fraction) {.numerator = 0, .denominator = 1};
	}

	fraction add;

	add.numerator = (*q1).numerator * (*q2).denominator + (*q2).numerator * (*q1).denominator;
	add.denominator = (*q1).denominator * (*q2).denominator;
	reduce_to_lowest(&add);

	return add;
}

fraction subtract_fraction(fraction *q1, fraction *q2) {
	// Check 0 division error
	if (zero_division_error_fraction(q1) || zero_division_error_fraction(q2)) {
		printf("Zero division error, process ignored.\n");
		return (fraction) {.numerator = 0, .denominator = 1};
	}

	fraction subtract;

	subtract.numerator = (*q1).numerator * (*q2).denominator - (*q2).numerator * (*q1).denominator;
	subtract.denominator = (*q1).denominator * (*q2).denominator;
	reduce_to_lowest(&subtract);

	return subtract;
}

fraction multiply_fraction(fraction *q1, fraction *q2) {
	// Check 0 division error
	if (zero_division_error_fraction(q1) || zero_division_error_fraction(q2)) {
		printf("Zero division error, process ignored.\n");
		return (fraction) {.numerator = 0, .denominator = 1};
	}

	fraction multiplication;

	multiplication.numerator = (*q1).numerator * (*q2).numerator;
	multiplication.denominator = (*q1).denominator * (*q2).denominator;
	reduce_to_lowest(&multiplication);

	return multiplication;
}

fraction divide_fraction(fraction *q1, fraction *q2) {
	// Check 0 division error
	if (zero_division_error_fraction(q1) || zero_division_error_fraction(q2)) {
		printf("Zero division error, process ignored.\n");
		return (fraction) {.numerator = 0, .denominator = 1};
	}
	
	if ((*q2).numerator == 0) {
		printf("The divisor is 0, zero division error.\n");
		printf("Process ignored.\n");
		return (fraction) {.numerator = 0, .denominator = 1};
	}

	fraction division;

	division.numerator = (*q1).numerator * (*q2).denominator;
	division.denominator = (*q1).denominator * (*q2).numerator;
	reduce_to_lowest(&division);

	return division;
}
