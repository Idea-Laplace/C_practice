/* Rewrite the temperature conversion program of Section 1.2 to 
 * use a function for conversion. */
#include <stdio.h>

float fahr2celsius(float fahr);

int main(void) {
	float fahr, celsius;

	printf("Fahrenheit   Celsius\n");
	printf("----------   -------\n");
	for (fahr = 0; fahr <= 300; fahr += 20) {
		celsius = fahr2celsius(fahr);
		printf("%9.0f    %6.1f \n", fahr, celsius);
	}

	return 0;
}

float fahr2celsius(float fahr) {
	return (5.0 / 9.0) * (fahr - 32);
}
