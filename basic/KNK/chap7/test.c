#include <stdio.h>
#include <stdlib.h>


int main (void) {
	int i;
	long long l;
	
	printf("size of i: %d\n", sizeof(i));
	printf("size of l: %d\n", sizeof(l));
	//=======================================
	i = 50000;
	l = i * i;
	printf("Value of i * i: %lld\n", l);
	//=======================================
	l = i * -i;
	printf("Value of i * -i: %lld\n", l);
	//=======================================
	i = 70000;
	l = i * i;
	printf("Value of i * i: %lld\n", l);
	//=======================================
	system("pause");
	return 0;
}
