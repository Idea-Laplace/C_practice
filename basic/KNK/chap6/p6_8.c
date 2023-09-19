#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int number_of_days, starting_day;
		printf("Enter number of days in month: ");
		scanf("%d", &number_of_days);
		if (number_of_days < 28 || number_of_days > 31){
			printf("Enter between 28 and 31.\n");
			continue;
		}
		printf("Enter starting day of the week (Sun ~ Sat match with 1 ~ 7): ");
		scanf("%d", &starting_day);
		if (starting_day < 1 || starting_day > 7){
			printf("Enter between 1 and 7.\n");
			continue;
		}
		getchar();

		printf("\n");
		for (int i = 1; i < starting_day; ++i)
			printf("   ");

		for (int i = 1; i <= number_of_days; ++i){
			printf(" %2d", i);
			if ((i + starting_day - 1) % 7 == 0)
				printf("\n");
		}

		if ((number_of_days + starting_day - 1) % 7 != 0)
			printf("\n");

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
	system("pause");
	return 0;
}
