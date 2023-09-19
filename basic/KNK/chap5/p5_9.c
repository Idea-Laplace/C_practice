#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int reply = 0;
		int month1, date1, year1, month2, date2, year2;

		printf("Only C.E. dates are allowed.\n");
		printf("This program won't check whether the input date is of correct form.\n");
		printf("Enter 1st date (mm/dd/yy): ");
		scanf("%d /%d /%d", &month1, &date1, &year1);
		printf("Enter 2nd date (mm/dd/yy): ");
		scanf("%d /%d /%d", &month2, &date2, &year2);
		getchar();
		
		if (year1 < year2)
			printf("%2.2d/%2.2d/%4.4d is earlier than %2.2d/%2.2d/%4.4d\n", month1, date1, year1, month2, date2, year2);
		else if (year1 > year2)
			printf("%2.2d/%2.2d/%4.4d is earlier than %2.2d/%2.2d/%4.4d\n", month2, date2, year2, month1, date1, year1);
		else
			if (month1 < month2)
				printf("%2.2d/%2.2d/%4.4d is earlier than %2.2d/%2.2d/%4.4d\n", month1, date1, year1, month2, date2, year2);
			else if (month1 > month2)
				printf("%2.2d/%2.2d/%4.4d is earlier than %2.2d/%2.2d/%4.4d\n", month2, date2, year2, month1, date1, year1);
			else
				if (date1 < date2)
					printf("%2.2d/%2.2d/%4.4d is earlier than %2.2d/%2.2d/%4.4d\n", month1, date1, year1, month2, date2, year2);
				else if (date1 > date2)
					printf("%2.2d/%2.2d/%4.4d is earlier than %2.2d/%2.2d/%4.4d\n", month2, date2, year2, month1, date1, year1);
				else
					printf("The given 2 dates are equal.\n");
		
			
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
	system("pause");
	return 0;
}
