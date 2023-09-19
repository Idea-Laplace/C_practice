#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i = 1;

	while (i <= 128){
		printf("%d\n", i);
		i *= 2;
	}
	system("pause");
	return 0;
}
