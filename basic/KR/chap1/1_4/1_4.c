#include <stdio.h>

// Write a program to print the corresponding Celsius to Fahrenheit table.

int main(void) {
	float celsius, fahr;
	int lower, upper, step;

	lower = -40; // Lower limit of temperature table.
	upper = 100; // Upper limit of */
	step = 20;   // Step size.
	
	celsius = lower;

	printf("Celsius    Fahrenheit\n");
	printf("------    ----------\n");
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32;
		printf("%7.0f   %10.1f\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}


