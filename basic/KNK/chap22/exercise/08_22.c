/*
   In previous chapters, we've used the scanf format string " %c"
   when we wanted to skip white space characters and read a nonblank
   character. Some programmers use "%1s" instead. Are the 2 techniques
   equivalent? If not, what are the difference?
*/

// No. The difference is that "%1s" will store a null character after
// it reads and stores a nonblank character; " %c" will store only the nonblank character.
// As a result, the two format strings must be used differently:
