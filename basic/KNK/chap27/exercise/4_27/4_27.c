/*
   Assume that the following variable declarations are in effect:

   int i;
   float f;
   double d;
   long double ld;
   float complex fc;
   double complex de;
   long double complex ldc;

   Each  of the following is an invocation of a macro in <tgmath.h>.
   Show what it will look like after preprocessing, when the macro
   has been replaced by a function from <math.h> or <complex.h>
*/


#include <tgmath.h>

int main(void) {
   int i = 0;
   float f = 0;
   double d = 0;
   long double ld = 0;
   float complex fc = 0;
   double complex de = 0;
   long double complex ldc = 0;

   tan(i);  // tan int->double
   fabs(f); // fabsf
   asin(d); // asin
   exp(ld); // expl
   log(fc); // clogf
   acosh(dc); // cacoshl
   nexttoward(d, ld); // nexttoward, ld is not generic type.
   remainder(f, i);   // remainder  int -> double
   copysign(d, ld);   // copysignl
   carg(i); // carg, int->double complex
   cimag(f); // cimagf
   conj(ldc); // conjl

   return 0;
}
