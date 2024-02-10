K. N. King C programming-A modern approach chap24.1 <assert.h>

void assert(scalar expression);

assert, which is defined in the <assert.h> header, allows a program
to monitor its own behaviour and detect possible problems at an early stage.

Although assert is actually a macro,
it's designed to be used like a function.

It has one argument, which must be an 'assertion'- an expression that
we expect to be true under normal curcumstance. Each time assert is
executed, it test the valus of its argument. if the argument has a nonzero
value, it does nothing.

If the argument's value is zero, however, assert writes a message to stderr
(the 'std'andard 'err'or stream) and calls the abort function to terminate
program execution.

Here is an example of using assert():

	assert(0 <= i && i <= 9);
	a[i] = 0;

C99 allows the value of its argument to be of a type other than that of integrals.
as long as they are scalar.

The exact form of the message produced by assert may vary from one compiler to another,
although it should always contain the information required by the standard.

********************************************************************************
#define NDEBUG  // Disables assert, Always prior to <assert.h>
#include <assert.h>

Avoid putting an expression that has a side effect, including a function call
inside an assert; If assert is disabled at a later date, the expression won't be
evaluated. Consider the following example:

assert((p = malloc(n)) != NULL);

If NDEBUG is defined, assert will be ignored and malloc won't be called.
********************************************************************************
