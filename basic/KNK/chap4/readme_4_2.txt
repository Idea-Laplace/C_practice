When it comes to / and % operator in C, we should be careful.

Let us think about i / j and i % j, where both of them are the type of int.

1. Both i and j are positive.
    a. Both C89 and C99 truncate the value of i/j by dropping the fractional
    part.
    b. If either operand is not an integer, then % would not be compiled.

2. Either i or j is negative.
    a. In C89, the value of i/j could be rounded either up or down, depending
    on its compiler.
    b. IN C89, the sign of i%j varies depending on its compliers.

    c. In C99, the value of i/j is always truncated toward 0.
    d. In C99, the sign of i%j is always same with the sign of i.

    so the thing is quite different to what in mathematics, where remainders
    must be nonnegative by the definition of remainder.
