#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIGIT 10


int main (void) {
	bool loop = true;
	int repdigit[DIGIT], digit;
	long long number;
	for (;;) {
		for (int i = 0; i < DIGIT; ++i)
			repdigit[i] = 0;

		printf("Enter a number: ");
		scanf("%lld", &number);
		
		if (number <= 0)
			break;

		while (number > 0) {
			digit = number % 10;
			++repdigit[digit];
			number /= 10;
		}

		printf("Digit:\t   ");
		for (int i = 0; i < DIGIT; ++i) {
			printf("  %2d", i);
		}

		printf("\n");
		printf("Occurences:");
		for (int i = 0; i < DIGIT; ++i) {
			printf("  %2d", repdigit[i]);
		}
		
		printf("\n");
		printf("Repeated digit(s): ");
		for (int i = 0; i < DIGIT; ++i) {
			if (repdigit[i] > 1)
				printf("%2d ", i);
		}
		printf("\n==============================\n");
	}
	printf("Program terminated.\n");
	system("pause");
	return 0;
}
