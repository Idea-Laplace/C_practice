#include <stdio.h>

#define CUBE(x) ((x)*(x)*(x))
#define REMAINDER_OF_FOUR(x) ((x) % 4)
#define HUNDRED_COMPARISION(x, y) ((x)*(y) < 100 ? 1 : 0)


int main(void) {
	int x, y;
	printf("Enter an integer x to get the cube value of x: ");
	scanf("%d", &x);
	getchar();
	printf("Cube of x: %d\n", CUBE(x));
	printf("Enter an integer x to get the remainder when divided by 4: ");
	scanf("%d", &x);
	printf("Cube of x: %d\n", REMAINDER_OF_FOUR(x));
	getchar();
	printf("Enter 2 integers to check whether their multiplication less than 100: ");
	scanf("%d %*1[^0-9]%d", &x, &y);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	printf("%d * %d is%sless than 100.\n", x, y, HUNDRED_COMPARISION(x, y) ? " " : " not ");
	return 0;
}
