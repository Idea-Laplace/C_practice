/*
   Write a program that prompts the user for a date (month, day and year)
   and an integer n, then prints the date that's n days later.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	int month, day, year;
	int n;
	char s[21];
	struct tm date;

	printf("Enter a date(mm/dd/yyyy): ");
	scanf(" %2d%*[ /:-]%2d%*[ /:-]%4d", &month, &day, &year);
	while (getchar() != '\n');

	printf("Enter n days you want to check after that day: ");
	scanf("%d", &n);

	/* initialize unused members */
	date.tm_sec = date.tm_min = date.tm_hour = 0;
	date.tm_isdst = -1;

	date.tm_year = year;
	date.tm_mon = month - 1;
	date.tm_mday = day + n;

	mktime(&date);

	strftime(s, sizeof(s), "%D", &date);
	printf("After %d days: %s\n", n, s);

	return 0;
}

