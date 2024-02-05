/* Assume that str is a string that contains a 'sales rank' immediately 
   preceded by the # symbol(other characters may precede the # and / or
   follow the sales rank). Asales rank is a series of decima digits possibly
   containing commas, such as the following examples:

   989
   24,675
   1,162,620

   Write a call of sscanf that extract the sales rank but not #symbol
   stores it in a string variable named sales_rank. */

#include <stdio.h>
#define LEN 20

int main(void) {
	char *sample = "The most motivated producted, ranked in" "#223,123,125\n";

	
	char sales_rank[LEN + 1];

	sscanf(sample, sample[0] == '#' ? "#%[0-9,]" : "%*[^#]#%[0-9,]", sales_rank);
	printf("%s", sample);
	printf("%s\n", sales_rank);
	return 0;
}
