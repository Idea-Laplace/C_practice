#include <stdio.h>
#include <stdlib.h>


int main(void){
	int sum = 0;
	for (int i = 0; i < 10; ++i){
		if (i % 2)
			continue;
		sum += i;
	}
	printf("%d, the sum of even numbers below 10.\n", sum);
	system("pause");
	return 0;
}
