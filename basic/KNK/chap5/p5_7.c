// Mission: Make a program that gets 4 integers as input,
// returns maximum and minimum numbers respectively using only 4 if statements.
// Strategy: tournament
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int reply = 0;
		int num1, num2, num3, num4;
		int max1, min1, max2, min2, max, min;
		printf("Enter 4 inteers in a row: ");
		scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
		getchar();

		max1 = num1; min1 = num2;
		max2 = num3; min2 = num4;
		if (num1 < num2){    // 1st if statement.
			max1 = num2;
			min1 = num1;
		}
		if (num3 < num4){   // 2nd if statement.
			max2 = num4;
			min2 = num3;
		}

		max = max1; min = min1;
		if (max1 < max2)    // 3rd if statement.
			max = max2;
		if (min1 > min2)    // 4th if and the last if statement.
			min = min2;
		
		printf("Largest: %d\n", max);
		printf("Smallest: %d\n", min);

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
