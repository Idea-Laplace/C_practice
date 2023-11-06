#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int power(int i);

int main(void) {
	int start, end;

	printf("Enter a start integer: ");
	scanf("%d", &start);
	printf("Enter an end integer: ");
	scanf("%d", &end);

	printf("The sum of all power() is %d\n", sum(&power, start, end));

	return 0;
}

int sum(int (*f)(int), int start, int end) {
	int total = 0;
	for (int i = start; i <= end; i++)
		total += f(i);

	return total;
}

int power(int i) {
	return i * i;
}



