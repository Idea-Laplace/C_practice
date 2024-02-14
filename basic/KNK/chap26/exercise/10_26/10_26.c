/*
   Convert the following calls of atoi, atol and atoll into calls of 
   strtoi, strtol, and strtoll, respectively.

   (a) atoi(str)
   (b) atol(str)
   (c) atoll(str)

   Ans)
   (a) strtoi(str, NULL, 10)
   (b) strtol(str, NULL, 10)
   (c) strtoll(str, NULL, 10)
*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *test = "3000000000";

	printf("%d\n", atoi(test));
	printf("%ld\n", strtol(test, NULL, 10));
	puts("");
	printf("%ld\n", atol(test));
	printf("%ld\n", strtol(test, NULL, 10));
	puts("");
	printf("%lld\n", atoll(test));
	printf("%lld\n", strtoll(test, NULL, 10));

	return 0;
}


