// KNK 2nd edition, chap11, problem7 p.255
#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Macro

// Prototype(s)
void split_date(int day_of_year, int year, int *month, int *day);


// Main
int main(void){
	bool loop = true;
	while (loop){
		int day_of_year, year;
		int month, day;
		printf("Enter day of year(1-365[366]): ");
		scanf("%d", &day_of_year);
		while (getchar() != '\n');

		printf("Enter a year(positive): ");
		scanf("%d", &year);
		while (getchar() != '\n');

		split_date(day_of_year, year, &month, &day);
		printf("Day %4d in year %4d: %2d/%2d/%4d.\n", day_of_year, year, month, day, year);


		// Loop decision
		char reply;
		do{
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch(reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first character.\n"); break;
			}
		} while(reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}


// Function(s)
void split_date(int day_of_year, int year, int *month, int *day){
	int year_normal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool rule_4, rule_100, rule_400;
	int truth_value;
	rule_4 = year % 4;
	rule_100 = year % 100;
	rule_400 = year % 400;
	truth_value = (int) rule_4 + rule_100 + rule_400;
	if (day_of_year <= 0){
		printf("Enter positive value on \'day_of_year\'\n");
		*month = *day = 0;
	}
	else {
		switch (truth_value){
			case 1: case 3:
				for (int i = 0; i < 12; ++i){
					if (day_of_year <= year_normal[i]){
						*month = i + 1;
						*day = day_of_year;
						break;
					}
					day_of_year -= year_normal[i];
				}
				break;
			case 0: case 2:
				for (int i = 0; i < 12; ++i){
					if (day_of_year <= year_leap[i]){
						*month = i + 1;
						*day = day_of_year;
						break;
					}
					day_of_year -= year_leap[i];
				}
				break;
			default :
				printf("Unexpected value Entered, try other proper values.\n");
				break;
		}
	}
}



