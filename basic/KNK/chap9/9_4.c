#include <stdio.h>
#include <stdlib.h>

// Leap year
#define LEAP_YEAR (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))

int day_of_year(int month, int day, int year);

int main(void) {
	for (;;) {
		int month, day, year;

		printf("Enter day of year(mm/dd/yyyy): ");
		scanf("%d /%d /%d", &month, &day, &year);
		getchar();

		printf("The day of the year: %3d\n", day_of_year(month, day, year));

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n==============================\n"); break;
				case 'n': printf("Program terminated.\n"); goto end;
				default : printf("Enter y or n.\n"); break;
			}
		} while (reply != 'y');
	}
	end:
	system("pause");
	return 0;
}


int day_of_year(int month, int day, int year) {
	const int year_array[12] = {31, 28 + LEAP_YEAR, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int total_days = 0;
	
	// Out of interval exception check
	if (year <= 0) {
		printf("Error: Only C.E. year allowed.\n");
		return -1;
	}
	if (month < 1 || month > 12) {
		printf("Error: Month out of range.\n");
		return -1;
	}
	if (day < 1 || day > year_array[month - 1]) {
		printf("Error: Date out of range.\n");
		return -1;
	}

	// Actual process
	for (int i = 1; i < month; ++i) 
		total_days += year_array[i - 1];
	total_days += day;

	return total_days;
}
