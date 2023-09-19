#include <stdio.h>
#include <stdlib.h>


int main(void){
	int i;
	char c;
	printf("Enter 2 same numbers(e.g. 5 5)): ");
	scanf("%d%c", &i, &c);
	printf("i: %d, c: %d\n", i, c);
	system("pause");
	return 0;
}
