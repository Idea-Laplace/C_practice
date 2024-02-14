/*
   Write a function that, when passed a year, returns a time_t value
   representing 12:00 a.m. on the first day of that year.
*/

#include <stdio.h>
#include <time.h>

time_t head_of_year(int year);

int main(void) {
	time_t head;
	int year;

	printf("Enter a year(1900~9999): ");
	scanf("%4d", &year);

	head = head_of_year(year);

	printf("%ld\n", head);

	return 0;
}

time_t head_of_year(int year) {
	struct tm temp;

	if (year < 1900) {
		fprintf(stderr, "Year out of ranage\n");
		return -1L;
	}

	temp.tm_year = year - 1900;
	temp.tm_sec = 0;
	temp.tm_min = 0;
	temp.tm_hour = 0;
	temp.tm_mday = 1;
	temp.tm_mon = 0;

	return mktime(&temp);
}
