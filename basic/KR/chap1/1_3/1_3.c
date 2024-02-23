/*
 * Print Fahenheit-Celsius table,
 * for fahr = 0, 20, 40, ... 300; floating point version
 *
 * Modify the temperature conversion program to print a heading above the table.
 */

#include <stdio.h>

int main(void) {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;    // lower limit of temperature table.
	upper = 300;  // Upper limit of temperature table.
	step = 20;    // step size.

	fahr = lower;

	printf("Fahrenheit   Celsius\n");
	printf("----------   -------\n");
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("       %3.0f   %7.1f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}

