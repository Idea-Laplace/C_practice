#include <stdio.h>


// Show how each of the following numbers will look if displayed 
// by %#012.5g as the conversion specification.

// #: Floating numbers always have a decimal point.
//  : trailing 0s aren't removed from numbers printed with the g or G conversion.

int main(void) {
	printf("%#012.5g\n", 83.7316);
	printf("00000083.732\n");
	printf("%#012.5g\n", 29748.6607);
	printf("00000029479.\n");
	printf("%#012.5g\n", 10594932234.0);
	printf("001.0594e+10\n");
	printf("%#012.5g\n", 0.0000235218);
	printf("002.3521e-05\n");
	printf("%a\n", 36.5);

	return 0;
}
