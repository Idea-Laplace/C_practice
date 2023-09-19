#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	bool loop = true;

	while(loop) {
		float epsilon, r_facto = 10.0f;
		double approx = 1.0;
		int reply = 0;

		printf("Enter a small value to confine value of adding term: ");
		scanf("%f", &epsilon);

		if (epsilon >= 1.00f) {
			printf("Value less than 1 is recommanded.\n");
			continue;
		}

		for (int i = 1; epsilon <= r_facto; ++i) {
			r_facto = 1.0f;
			for (int j = 1; j <= i; ++j)
				r_facto /= j;
			approx += r_facto;
		}
		printf("The approx of e with less difference than %f is %lf.\n", epsilon,  approx);
		getchar();

		while (reply != 'y' && reply != 'n'){
			printf("\nLoop this program?(y/n) > ");
			reply = getchar();
			getchar();

			switch(reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("\nProgram terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		}
	}
	system("pause");
	return 0;
}
