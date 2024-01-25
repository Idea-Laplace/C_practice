#include <stdio.h>

// Let f be the following function:
unsigned int f(unsigned int i, int m, int n) {
	return (i >> (m + 1 - n)) & ~(~0 << n);
}

// (a) What is the value of ~(~0 << n)?
// (b) What does the function do?

/*
   (a) ~0 is an idiom expression for bits only with 1.
   ~0 << n is a series of 1 bits with trailing n 0 bits,
   so ~(~0 << n) is a binary representation for 2^n - 1,
   which is 000...000111...111(ones of n bits).
   if n is too large or too small, n is scaled by the sizeof unsigned int.

   (b) When m >= n - 1, it sets 2^(m-n+1) bit to the 2^0 bit.
   and with & ~(~0 << n), from 2^m bit to 2^(m-n+1) bit

*/

