#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	bool loop = true;

	while(loop) {
		int reply = 0;
		int month1, date1, year1, month2, date2, year2;

		printf("Only C.E. dates are allowed.\n");
		printf("This program won't check whether the input date is of correct form.\n");
		
		// Initial case
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d /%d /%d", &month1, &date1, &year1);

		if (year1 <= 0 && month1 <= 0 && date1 <= 0)
			printf("0/0/0 is the earlist date.(default output)\n");
		else {
			while (true) {
				printf("Enter a date (mm/dd/yy): ");
				scanf("%d /%d /%d", &month2, &date2, &year2);

				if (year2 <= 0 && month2 <= 0 && date2 <= 0)
					break;
				
				// Renew earliest
				if (year1 > year2 || (year1 == year2 && month1 > month2) ||\
					(year1 == year2 && month1 == month2 && date1 > date2)) {
						month1 = month2;
						date1 = date2;
						year1 = year2;
				}
			}
			// Output
			printf("%.2d/%.2d/%.4d is the earlist date.\n", month1, date1, year1);
		}

		getchar();
		
			
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
