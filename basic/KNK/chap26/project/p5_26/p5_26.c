/*
   Write a program that prompts the user to enter two dates, then prints
   the difference between them, measured in days.
	Hint: Use the mktime and difftime functions.
*/

#include <stdio.h>
#include <time.h>

int main(void) {
	struct tm date1, date2, diff;
	time_t t_date1, t_date2;
	double t_diff;
	

	printf("Enter date 1(mm/dd/yyyy): ");
	scanf("%2d%*[/:-]%2d%*[/:-]%4d", &date1.tm_mon, &date1.tm_mday, &date1.tm_year);
	printf("Enter date 2(mm/dd/yyyy): ");
	scanf("%2d%*[/:-]%2d%*[/:-]%4d", &date2.tm_mon, &date2.tm_mday, &date2.tm_year);

	date1.tm_sec = date1.tm_min = date1.tm_hour = 0;
	date1.tm_isdst = -1;
	date2.tm_sec = date2.tm_min = date2.tm_hour = 0;
	date2.tm_isdst = -1;

	date1.tm_mon--;
	date2.tm_mon--;

	t_date1 = mktime(&date1);
	t_date2 = mktime(&date2);
	t_diff = difftime(t_date1, t_date2);

	printf("Difference : %.1f day(s)\n", t_diff / 86400);
	return 0;
}


