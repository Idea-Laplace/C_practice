#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		char type;
		int num;
		printf("First choose type of arithmetic variable(c/h/i/l/L/f/d/D): ");
		scanf(" %c", &type);
		printf("Enter a positive integer: ");
		scanf("%d", &num);
		getchar();

		switch (type) {
			case 'c':;
				char facto_c = 1;
				for (int i = 1; i <= num; ++i)
					facto_c *= i;
				printf("Factorial of %d: %d\n", num, facto_c);
				break;

			case 'h':;
				short facto_h = 1;
				for (int i = 1; i <= num; ++i)
					facto_h *= i;
				printf("Factorial of %d: %hd\n", num, facto_h);
				break;
			case 'i':;
				int facto_i = 1;
				for (int i = 1; i <= num; ++i)
					facto_i *= i;
				printf("Factorial of %d: %d\n", num, facto_i);
				break;
			case 'l':;
				long facto_l = 1;
				for (int i = 1; i <= num; ++i)
					facto_l *= i;
				printf("Factorial of %d: %ld\n", num, facto_l);
				break;
			case 'L':;
				long long facto_L = 1;
				for (int i = 1; i <= num; ++i)
					facto_L *= i;
				printf("Factorial of %d: %lld\n", num, facto_L);
				break;
			case 'f':;
				float facto_f = 1.0f;
				for (int i = 1; i <= num; ++i)
					facto_f *= i;
				printf("Factorial of %d: %f\n", num, facto_f);
				break;
			case 'd':;
				double facto_d = 1.0;
				for (int i = 1; i <= num; ++i)
					facto_d *= i;
				printf("Factorial of %d: %f\n", num, facto_d);
				break;
			case 'D':;
				long double facto_D = 1.0l;
				for (int i = 1; i <= num; ++i)
					facto_D *= i;
				printf("Factorial of %d: %f\n", num, facto_D);
				break;
			default : printf("Invalid type input, try again.\n"); continue;
		}

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
