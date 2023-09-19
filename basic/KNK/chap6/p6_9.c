#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		float loan, interest, payment; // Identifiers for calculation.
		int count_payment;             // Determinate what time the process run through.
		int reply = 0;                 // for subloop.

		printf("Enter amount of loan: ");
		scanf("%f", &loan);
		printf("Enter interest rate(%%, per year): ");
		scanf("%f", &interest);
		printf("Enter monthly payment: ");
		scanf("%f", &payment);
		printf("Enter number to cycle: ");
		scanf("%d", &count_payment);
		getchar();                           // Littering '\n' to getchar.
		printf("\n");
		
		interest = 0.01f * interest / 12;    // Turning to monthly interest rate.

		for (int i = 1; i <= count_payment; ++i) {
			loan = loan * (1 + interest) - payment;
			printf("Balance remaining after ");

			if (i % 100 > 10 && i % 100 < 20)
				printf("%dth payment: $%.2f\n", i, loan);
			else
				switch (i % 10) {
					case 1: printf("%dst payment: $%.2f\n", i, loan); break;
					case 2: printf("%dnd payment: $%.2f\n", i, loan); break;
					case 3: printf("%drd payment: $%.2f\n", i, loan); break;
					default : printf("%dth payment: $%.2f\n", i, loan); break;
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
