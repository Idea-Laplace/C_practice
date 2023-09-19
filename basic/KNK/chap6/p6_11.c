#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	bool loop = true;

	while(loop) {
		int n;
		double approx = 1.0;
		int reply = 0;

		printf("Enter a number n to computing e up to nth Taylor sum: ");
		scanf("%d", &n);

		if (n < 0) {
			printf("Enter a nonnegative integer.\n");
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			int facto = 1;
			for (int j = 1; j <= i; ++j)
				facto *= j;
			approx += 1.0 / facto;
		}
		printf("The Taylor sum of e of %dcycle(s) is %lf.\n", n,  approx);
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
