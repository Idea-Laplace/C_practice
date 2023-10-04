#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FLUSH while (getchar() != '\n')


typedef struct {
	int month, day, year;
} date;

// Function prototype(s)
int day_of_year(date d);
int compare_dates(date d1, date d2);

int main(void){
	bool loop = true;
	date date1;
	date date2;

	while(loop){

		printf("Only C.E. dates are allowed.\n");
		printf("This program won't check whether the input date is of correct form.\n");

		printf("Enter 1st date (mm/dd/yy): ");
		scanf("%d /%d /%d", &date1.month, &date1.day, &date1.year);
		FLUSH;

		printf("Enter 2nd date (mm/dd/yy): ");
		scanf("%d /%d /%d", &date2.month, &date2.day, &date2.year);
		FLUSH;

		if (compare_dates(date1, date2) > 0)
			printf("Date 1 is later than date 2.\n");
		else if (compare_dates(date1, date2) < 0)
			printf("Date 1 is earlier than date 2.\n");
		else
			printf("The given 2 dates are equal.\n");
		
		// Loop decision
		int reply = 0;
		while (reply != 'y' && reply != 'n'){
			printf("\nLoop this program?(y/n) > ");
			reply = getchar();
			getchar();

			switch(reply){
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("\nProgram terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		}
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
