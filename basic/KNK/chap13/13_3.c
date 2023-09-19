#include <stdio.h>
#include <stdlib.h>


int main(void){
	int i, j;
	char *s;

	printf("scanf(\"%%d%%s%%d\", &i, s, &j), input 12abc34 56def78, the result is:\n");
	scanf("%d%s%d", &i, s, &j);
	printf("i: %d, s: %s, j: %d\n", i, s, j);
	system("pause");
	return 0;
}
