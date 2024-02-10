In the inventory.c program (see Section 16.3), the main function has a for loop
that prompts the user to enter an operation code, reads the code, and then calls
either insert, search, update, or print. Add a call of setjump to main in such a
way that a subsequent call of longjmp will return to the for loop. (After the 
longjmp, the user will be prompted for an operation code, and the program will 
continue normally.) setjmp will need a jmp_buf; where should it be declared?


K. N. King C programming - A modern approach, 2nd edition. chap24 setjump & longjmp

int setjmp(imp_buf env);  // env for 'environment'.
void longjmp(jmp_buf env, int val);

Normally, a function returns to the point at which it was called. We can't use a
goto statement to make it go elswhere, because a goto can jump only to a label
within the same function. The <setjmp.h> header, however, makes it possible for 
one function to jump directly to another function without returning.

The most important item in <setjmp.h> are setjmp 'macro' and the longjmp 'function'.
setjmp marks a place in a program; longjmp can then be used to return to that place
later. Although this powerful mechanism has a variety of potential applications, it's
used primarily for error handling.

To mark the target of a future jump, we call setjmp, passing it a variable of type
jmp_buf (declared in <setjmp.h>). setjmp stores the current "environment" (includ-
ing a pointer to the location of the setjmp itself) in the variable for later use
in call of longjmp; it then returns zero.
(ONLY the 1st call, setjmp returns 0, )



