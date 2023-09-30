//KNK(2008) C programming - A moderen approach 2nd edition
//chapter 16 Ex 17, p.411


#include <stdio.h>

int main(void) {
	enum {FALSE, TRUE} mybool;
	int i;

	mybool =  FALSE; // (a)
	mybool = i;  // (b)
	mybool++;   // (c)
	i = mybool;  // (d)
	i = 2 * mybool + 1; // (e)

	mybool = 2;
	printf("%d\n", mybool);

	printf("All expressions are legal, but only a, d, e are safe.\n");
	return 0;
}
