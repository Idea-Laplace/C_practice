#ifndef FRACTION_H
#define FRACTION_H

// Type definition of fraction, which consists of
// numerator and denominator.
typedef struct {
	int numerator;
	int denominator;
} fraction;


// Zero division error warning function
_Bool zero_division_error_fraction(fraction *quotient);

/**
 * reduce_to_lowest: This function has a fraction as its parameter.
 *                   It reduce the fraction to its lowest terms.
 *
 * quotient        : The parameter of the function reduce_to_lowest.
 *                   It is a fraction struct type.
 **/
void reduce_to_lowest(fraction *quotient);


// Aritmatical functions for fractions.
fraction add_fraction(fraction *q1, fraction *q2);
fraction subtract_fraction(fraction *q1, fraction *q2);
fraction multiply_fraction(fraction *q1, fraction *q2);
fraction divide_fraction(fraction *q1, fraction *q2);

#endif
