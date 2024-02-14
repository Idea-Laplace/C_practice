/*
   Write a function named display that takes any number of arguments.
   The first argument, which must be an integer. The remaining arguments
   will be strings. The first argument specifies how many strings the call
   contains. The function will print the strings on a single line, with
   adjacent strings spearated by one space. For example, the call

   display(4, "special", "Agent", "Dale", "Cooper");
   
   will produce the following output:

   Special Agent Dale Cooper
*/

#include <stdarg.h>
#include <stdio.h>

void display(int n, ...);

int main(void) {
	const char *season[4] = {"Spring", "Summer", "Fall", "Winter"};

	for (int i = 1; i <= 4; i++) {
		display(i, season[0], season[1], season[2], season[3]);
		printf("\n");
	}

	return 0;
}

void display(int n, ...) {
	va_list sl;
	va_start(sl, n);
	for (int i = 0; i < n; i++) 
		printf("%s ", va_arg(sl, char *));
}



