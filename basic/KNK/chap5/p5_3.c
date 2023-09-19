#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int reply = 0;
		float commission, number_of_shares, price_per_share, value;
		
		printf("Enter number of shares: ");
		scanf("%f", &number_of_shares);
		printf("Enter price per share: ");
		scanf("%f", &price_per_share);
		getchar();
		value = number_of_shares * price_per_share;
		
		if (value < 2500.00f)
			commission = 30.00f + .017f * value;
		else if (value < 6250.00f)
			commission = 56.00f + .0066f * value;
		else if (value < 20000.00f)
			commission = 76.00f + .0034f * value;
		else if (value < 50000.00f)
			commission = 100.00f + .0022f * value;
		else if (value < 500000.00f)
			commission = 155.00f + .0011f * value;
		else
			commission = 255.00f + .0009f * value;

		if (commission < 39.00f)
			commission = 39.00f;

		printf("Commission: $%.2f\n", commission);
		if (number_of_shares < 2000)
			printf("Rival's commission: $%.2f\n", 33.00f + number_of_shares * 0.03f);
		else
			printf("Rival's commission: $%.2f\n", 33.00f + number_of_shares * 0.02f);

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
