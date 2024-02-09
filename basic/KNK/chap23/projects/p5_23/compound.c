#include <math.h>
#include <stdio.h>

double compound(double deposit, double interest, int years);

int main(void) {
	double deposit, interest_rate;
	double get_amount;
	int years;

	printf("Enter initial deposit($): ");
	scanf("%lf", &deposit);
	while (getchar() != '\n');

	printf("Enter interest rate(%%): ");
	scanf("%lf", &interest_rate);
	while (getchar() != '\n');

	printf("Enter years to left on: ");
	scanf("%d", &years);
	while (getchar() != '\n');

	get_amount = compound(deposit, interest_rate, years);

	printf("You would get: $%.2f\n", get_amount);
	return 0;
}

double compound(double deposit, double interest, int years) {
	return deposit * exp(interest * years / 100);
}
