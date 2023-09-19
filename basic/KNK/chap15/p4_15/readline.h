#ifndef READ_LINE
#define READ_LINE

// The read_line function accepts input characters and 
// store them in the str[] parameter as a string.
// The length of 'str[]' should be larger than the 'string_length'
// as least by 1 so that the str[] could have a space to
// store '\0', the null character at the end of the input.
//
// ex) 
// #define MAX_LINE_LEN 60
// ...
// char str[MAX_LINE_LEN + 1];
// ...
// read_line(str, MAX_LINE_LEN);

int read_line(char str[], int string_length);

#endif
