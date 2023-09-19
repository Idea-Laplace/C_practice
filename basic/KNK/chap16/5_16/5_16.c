/**
 * Write the following functions, assuming that the date
 * structure contains 3 members: month, day, and year.
 * (all of type int)
 *
 * (a) int day_of_year(struct date d);
 * Returns the day of the year (an integer between 1 and 366)
 * that corresponds to the date d.
 *
 * (b) int compare_dates(struct date d1, struct date d2);
 * Returns -1 if d1 is an earlier date than d2, +1 if d1 is 
 * a later date than d2, and 0 if d1 and d2 are the same.
 **/


#include <stdio.h>
#include <stdbool.h>
#include "loop_decision.h"


// Type definition
typedef struct {
	int month, day, year;
} date;


// Function prototype(s)
// (a)
int day_of_year(date d);
// (b)
int compare_dates(date d1, date d2);


// Main
int main(void) {
	date d1, d2;
	bool loop = true;

	while (loop) {
		printf("Enter month, day, year of form mm/dd/yyyy for d1: ");
		if (scanf("%2d /%2d /%4d", &d1.month, &d1.day, &d1.year) != 3) {
			printf("Invalid input, process restarts.\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');
		printf("Enter month, day, year of form mm/dd/yyyy for d2: ");
		if (scanf("%2d /%2d /%4d", &d2.month, &d2.day, &d2.year) != 3) {
			printf("Invalid input, process restarts.\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');

		printf("d1: %02d/%02d/%4d\n", d1.month, d1.day, d1.year);
		printf("d2: %02d/%02d/%4d\n", d2.month, d2.day, d2.year);

		printf("\nd1-total date: %3d\n", day_of_year(d1));
		printf("d2-total date: %3d\n", day_of_year(d2));

		if (compare_dates(d1, d2) == 0)
			printf("d1 and d2 are same.\n");
		else if (compare_dates(d1, d2) > 0)
			printf("d1 is later than d2.\n");
		else
			printf("d1 is earlier than d2.\n");

		loop_decision(&loop);
	}

	return 0;
}


int day_of_year(date d) {
	const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int temp = d.day;

	for (int i = 0; i < d.month - 1; i++)
		temp += days[i];
	
	return temp;
}

int compare_dates(date d1, date d2) {
	if (d1.year != d2.year)
		return d1.year > d2.year ? 1 : -1;
	
	if (day_of_year(d1) == day_of_year(d2))
		return 0;
	else
		return day_of_year(d1) > day_of_year(d2) ? 1 : -1;
}



