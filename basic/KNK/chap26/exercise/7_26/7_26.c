/*
   Explain the meaning of the following statement, assuming that value
   is a variable of type long int and p is a variable of type char *

   value = strtol(p, &p, 10);
*/

/*
   The second argument indicates whether the mapping has been entirely done.
   If the mapping were done entirely, the argument would point null charater
   of the first argument. which results change of value of p to null. If the
   conversion was not entirely done, the p move to the first character that
   can't by convertied. (of form base 10, of course by the 3rd argument.)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *p = "31.41592";
	long value;
	
	printf("This program is for the learning of how value = strtol(p, &p, 10); works\n");
	printf("p: %s\n", p);
	value = strtol(p, &p, 10);
	printf("value: %ld\n", value);
	printf("p: %s\n", p);

	return 0;
}
