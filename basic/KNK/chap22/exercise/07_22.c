/*
   Suppose that we call scanf as follows:
   n = scanf("%d%f%d", &i, &x, &j);
   i, j and n are int variables and x is a float variable.)
   Assuming that the input stream contains the characters show,
   give the values of i, k, n and x after the call. In addition,
   indicate which charcters were consumed by the call.

   (a) 10 20 30\n     i = 10, x = 20.0, j = 30, n = 3;
   (b) 1.0 2.0 3.0\n  i = 1 , x = 0.0, j = 2 , n = 3;
   (c) 0.1 0.2 0.3\n  i = 0 , x = 0.1, j = 0 n = 3;
   (d) .1 .2 .3\n     i -   , x -    , j -  , n = 0;

*/

#include <stdio.h>

int main(void) {
	int i, j, n;
	float x;

	while ((n = scanf("%d%f%d", &i, &x, &j)) != EOF) {
		printf("i : %4d\n", i);
		printf("x : %4.1f\n", x);
		printf("j : %4d\n", j);
		printf("n : %4d\n", n);
		puts("");

		i = j = -1;
		x = -1;
		
		while (getchar() != '\n');
	}

	return 0;
}
