K. N. King C programming 2nd edition, chap23 exercise 2, p624.

(C99) Write the following function

double evaluate_polynomial (double a[], int n, double x);

The function should store the value of the polynomial a_nx^n + ... a_0;
where the a_i's are stored in corresponding elements of the array a, wh-
-ich has length n + 1. Have the function usw 'Horner's Rule' to compute
the value of the polynomial

Use the fma function to perfom the multiplications and additions.
