#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i = 9384;
	do {
		printf("%d\n", i);
		i /= 10;
	} while (i > 0);
	system("pause");
	return 0;
}

