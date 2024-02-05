/*
   The following loop appears in the fcopy.c program:
   while ((ch = getc(source_fp)) != EOF)
       putc(ch, dest_fp);

   suppose that we neglected to put parentheses around ch = getc(sourc_fp):

   while (ch = getc(source_fp) != EOF)
       putc(ch, dest_fp);

   Would the program compile wothout an erro? If so, what would the program do when
   it's run?
*/

// It writes a series of 1(ctrl + A, actually) on dest_fp file until it meets EOF, which prints 0.
