/*
   (a) Write a 'wrapper' function named 'try_math_fcn' that call a math function
       (assumed to have a double argument and return a double value) and then 
	   checks whether the call succeeded. Here's how we might use try_math_fcn:

	   y = try_math_fcn(sqrt, x, "Error in call of sqrt");

	   If the call sqrt(x) is successful, try_math_fcn returns the value compu-
	   -ted by sqrt. If call fails, try_math_fcn calls perror to print the mes-
	   -sage 'Error in call of sqrt', then calls exit to terminate the program.

	(b) Write a macro that has the same effect as try_math_fcn but builds the 
	    error message from the function's name:

		y = TRY_MATH_FCN(sqrt, x);
		
		If the call of sqrt fails, the message will be error in call of sqrt.
		Hint: Have TRY_MATH_FCN call try_math_fcn.
*/

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TRY_MATH_FCN(f, x) try_math_fcn((f), (x), "Error in call of " #f ".")

double try_math_fcn(double (*f)(double), double x, char *error_message);

int main(void) {
	double x;
	x = 5929.;
	x = -1.;
	//printf("Square root of %f: %f\n", x, try_math_fcn(sqrt, x, "Error in call of sqrt."));
	printf("(MACRO)Square root of %f: %f\n", x, TRY_MATH_FCN(sqrt, x));


	return 0;
}

double try_math_fcn(double (*f)(double), double x, char *error_message) {
	double value;

	errno = 0;
	value = (*f)(x);

	if (errno != 0) {
		// Normally perror add line feed character at the end of the message.
		perror(error_message);
		exit(EXIT_FAILURE);
	}

	return value;
}

