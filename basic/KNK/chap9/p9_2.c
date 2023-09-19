/*************************************************************
 *    Income                      Amount of tax              *
 * Not over $750      1% of income                           *
 * $750 ~ $2,250      $7.50 + (2% of amount of over $750     *
 * $2,250  ~ $3,750   $37.50 + (3% of amount of over $2,250  *
 * $3,750 ~ $5,250    $82.50 + (4% of amount of over $3,750  *
 * $5,250 ~ $7,000    $142.50 + (5% of amount of over $5,250 *
 * Over $7,000        $230.00 + (6% of amount of over $7,000 *
 * ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void income_tax(float income);

int main(void){
	bool loop = true;

	while(loop){
		int reply = 0;
		float income;
		printf("Enter taxable income: ");
		scanf("%f", &income);
		getchar();

		income_tax(income);


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


void income_tax(float income) {
	if (income < 750)
		printf("Tax due: $%g\n", 0.01f * income);
	else if (income < 2250)
		printf("Tax due: $%g\n", 7.50f +  0.02f * (income - 750));
	else if (income < 3750)
		printf("Tax due: $%g\n", 37.50f +  0.03f * (income - 2250));
	else if (income < 5250)
		printf("Tax due: $%g\n", 82.50f +  0.04f * (income - 3750));
	else if (income < 7000)
		printf("Tax due: $%g\n", 142.50f +  0.05f * (income - 5250));
	else
		printf("Tax due: $%g\n", 230.00f +  0.06f * (income - 7000));
}
