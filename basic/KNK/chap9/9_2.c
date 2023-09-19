#include <stdio.h>
#include <stdlib.h>


int check(int x, int y, int n);

int main(void) {
	int x, y, n;
	for(;;) {
		printf("Enter a number to restrict interval: ");
		scanf("%d", &n);
		printf("Enter 2 numbers to be tested[x, y]: ");
		scanf("%d ,%d", &x, &y);
		getchar();

		printf("Inclusive decision: %d\n", check(x, y, n));

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n==============================\n"); break;
				case 'n': printf("Program terminated.\n"); goto out;
				default : printf("Type y or n.\n"); break;
			}
		}
		while (reply != 'y' && reply != 'n');
	}
	out:
	system("pause");
	return 0;
}

int check(int x, int y, int n) {
	if (x < 0 || y < 0)
		return 0;
	if (x > n - 1 || y > n - 1)
		return 0;
	return 1;
}
