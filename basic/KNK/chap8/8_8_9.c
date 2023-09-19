#include <stdio.h>
#include <stdlib.h>
#define DAYS 30
#define HOURS 24

void average(float a[][HOURS]);

int main(void) {
	float temperature_readings[DAYS][HOURS];
	float chaos; 

	printf("Enter any real number between 0.25 and 0.75 to initalize temperature: ");
	scanf("%f", &chaos);
	
	for (int i = 0; i < DAYS; ++i) {
		chaos = chaos * (1 - chaos);
		for (int j = 0; j < HOURS; ++j) {
			temperature_readings[i][j] = 5 + chaos + j * (28 - j) / 10;
		}
	}
	
	for (int i = 0; i < DAYS; ++i) {
		for (int j = 0; j < HOURS; ++j)
			printf("%5.1fC", temperature_readings[i][j]);
		printf("\n");
	}
	average(temperature_readings);
	system("pause");
	return 0;
}

void average(float a[][HOURS]) {
	float day_avg[DAYS] = {0.0f}, month_avg;
	for (int i = 0; i < DAYS; ++i) {
		for (int j = 0; j < HOURS; ++j)
			day_avg[i] += a[i][j];
		day_avg[i] /= HOURS;
		printf("Average temperature of day %2d: %3.1fC\n", i, day_avg[i]);
	}

	printf("\n");
	for (int i = 0; i < DAYS; ++i) {
		month_avg += day_avg[i];
	}
	month_avg /= DAYS;
	printf("Average temperature of the given month: %3.1fC\n", month_avg);
}


