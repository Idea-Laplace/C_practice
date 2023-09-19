#include <stdio.h>
#include <stdlib.h>
#define NUM_RATES (int) (sizeof(value) / sizeof(value[0]))
#define INITIAL_BALANCE 100.00

int main(void) {
	int low_rate, num_years, year;
	double value[5];

	printf("Enter interest rate: ");
	scanf("%d", &low_rate);
	printf("Enter number of years: ");
	scanf("%d", &num_years);

	printf("\nYears month");
	for (int i = 0; i < NUM_RATES; ++i) {
		printf("%3d%%   ", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	for (year = 0; year <= num_years; ++year) {
		for (int month = 1; month <= 12; ++month) {
			if (month == 1)
				printf("%3d%7d", year, month);
			else
				printf("     %5d", month);

			for (int i = 0; i < NUM_RATES; ++i) {
				value[i] += ((double) (low_rate + i) / 12) / 100.0 * value[i];
				printf("%7.2f", value[i]);
			}
			printf("\n");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

