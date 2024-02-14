/*
   Write the following function:

   char *max_pair(int num_pairs,...);

   The arguments of max_pair are assumed to by 'pairs' of integers and strings;
   the value of num_pairs indicates how many pairs will follow. (A pair consists
   of an int argument followed by a char * argument)/ The function searches the 
   integers to fine the largest one; it then returns the string argument that 
   follows it.
*/

#include <stdarg.h>
#include <stdio.h>

char *max_pair(int num_pairs, ...);

int main(void) {
	char *str;

	str = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",\
					39, "The Honeymooners", 210, "All in the Family",\
					86, "The Sopranos");

	printf("%s\n", str);
	return 0;
}

char *max_pair(int num_pairs, ...) {
	int largest, temp;
	char *cor_str;
	va_list pl;

	va_start(pl, num_pairs);
	largest = temp = va_arg(pl, int);
	cor_str = va_arg(pl, char *);

	for (int i = 1; i < num_pairs; i++) {
		temp = va_arg(pl, int);
		if (temp > largest) {
			largest = temp;
			cor_str = va_arg(pl, char *);
			continue;
		}
		va_arg(pl, char *);
	}

	va_end(pl);
	return cor_str;
}
