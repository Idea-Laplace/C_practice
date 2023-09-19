#include <stdio.h>
#include <stdlib.h>
#define TOTAL_SUBTRACTION 1
#define TRUE 1
#define FALSE 0


int main(void){
	_Bool loop = TRUE, mode;                  // Variables for loop or determining process.

	while(loop){
		int reply = 0;
		int upc[11], ean[12], check_point;        // Variables containing input digits.
		int first_sum = 0, second_sum = 0, total; // Variables for processing.
		printf("Enter either 1(for UPC) or 0(for EAN) each of which you want to examine the validity: ");
		scanf("%d", &mode);
		if (mode == 1){
			printf("Enter the entire 12 digits of a UPC: ");
			for (int i = 0; i < 11; ++i){
				scanf("%1d", &upc[i]);
				if (i % 2 == 0)
					first_sum += upc[i];
				else
					second_sum += upc[i];
			}
			scanf("%1d", &check_point);
			total = 3 * first_sum + second_sum - TOTAL_SUBTRACTION;
			printf("Check digit: %d\n", check_point);
			printf("Calculated check digit: %d\n", 9 - total % 10);

			if (check_point == 9 - total % 10)
				printf("Valid UPC number array.\n");
			else
				printf("Invalid UPC number array.\n");
		}
		else{
			printf("Enter the entire 13 digits of a EAN: ");
			for (int i = 0; i < 12; ++i){
				scanf("%1d", &ean[i]);
				if (i % 2 == 0)
					second_sum += ean[i];
				else
					first_sum += ean[i];
			}
			scanf("%1d", &check_point);
			total = 3 * first_sum + second_sum - 1;
			printf("Check digit: %d\n", check_point);
			printf("Calculated check digit: %d\n", 9 - total % 10);

			if (check_point == 9 - total % 10)
				printf("Valid EAN number array.\n");
			else
				printf("Invalid EAN number array.\n");
		}
		getchar();

		// Loop decision
		while (reply != 'y' && reply != 'n'){
			printf("\nLoop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply){
				case 'y': printf("=================================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = FALSE; break;
				default : printf("Type y or n.\n"); break;
			}
		}
	}
    system("pause");
    return 0;
}
