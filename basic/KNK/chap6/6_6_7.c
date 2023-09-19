#include <stdio.h>
#include <stdlib.h>


int main(void){
	printf("Your loop code must be only consist of for statement.\n");

	printf("6_1.c code with for statement instead of while.\n");
	for (int i = 1; i <= 128; i *= 2)
		printf("%d ", i);
	printf("\n");

	printf("6_2.c code with for statement instead of while.\n");
	for (int i = 9384; i > 0; i /= 10)
		printf("%d ", i);
	printf("\n");

	system("pause");
	return 0;
}
