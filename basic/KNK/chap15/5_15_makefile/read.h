#ifndef READ_LINE
#define READ_LINE
#define MAX_LINE_LEN 100

// read_line(char *str, size_t len_str)
// read_line: The read_line function basically reads input string,
// stores it and returns the length of input string.
// If a string is too long to store in str[], remaining characters
// will be decayed to single '*' character followed by str[].

// *str : Parameter which accept a char type array.
// len_str : Length of *str should have 2 more spaces than maximum input length,
// one for '*', and the other for '\0'

int read_line(char *str, size_t len_str);

#endif
