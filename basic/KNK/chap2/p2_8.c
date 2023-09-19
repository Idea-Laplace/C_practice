#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		float loan, interest, payment; // Identifiers for calculation.
		int reply = 0; // for subloop.

		printf("Enter amount of loan: ");
		scanf("%f", &loan);
		printf("Enter interest rate(%%, per year): ");
		scanf("%f", &interest);
		printf("Enter monthly payment: ");
		scanf("%f", &payment);
		getchar();                           // Littering '\n' to getchar.
		printf("\n");
		
		interest = 0.01f * interest / 12;    // Turning to monthly interest rate.

		for (int i = 1; i <= 3; ++i) {
			loan = loan * (1 + interest) - payment;
			printf("Balance remaining after ");
			switch (i) {
				case 1: printf("first payment: $%.2f\n", loan); break;
				case 2: printf("second payment: $%.2f\n", loan); break;
				case 3: printf("third payment: $%.2f\n", loan); break;
				default : break;
			}
		}

		while (reply != 'y' && reply != 'n') {
			printf("\nLoop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("=================================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n");
			}
		}
	}
	system("pause");
	return 0;
}



	int loan, interest, payment;
