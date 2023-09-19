#include <stdio.h>
#include <stdlib.h>


int main(void){
	printf("This output is made by continue statement.\n");
	for (int i = 0; i < 100; ++i){
		if ( i % 2 == 0)
			continue;
		printf("%d\n", i);
	}
	
	printf("This output is made by goto statement.\n");
	for (int i = 0; i < 100; ++i){
		if ( i % 2 == 0)
			goto end;
		printf("%d\n", i);
		end:;
	}
	system("pause");
	return 0;
}
