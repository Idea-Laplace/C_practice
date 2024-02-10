#ifndef _ADDITIONAL_STRING_H
#define _ADDITIONAL_STRING_H

/******************************************************
 * strdup:                                            *
 * Returns a pointer to a copy of s store in memory   * 
 * obtained by calling malloc. Returns a null pointer *
 * if enough memory couldn't be allocated.            *
 ******************************************************/
char *strup(char *s);

/******************************************************
 * stricmp:                                           *
 * Similar to strcmp, but ignores the case of letters.*
 ******************************************************/
int stricmp(char *s1, char *s2);

/******************************************************
 * strlwr:                                            *
 * Converts upper case letters in to lower case, lea- *
 * -ving other characters unchanged; returns s.       *
 ******************************************************/
char *strlwr(char *s);

/******************************************************
 * strrev:                                            *
 * Reverses the characters in s(except the null char- *
 * -acter); returns s;                                *
 ******************************************************/
char *strrev(char *s);

/******************************************************
 * strset:                                            *
 * Fills s with copies of the character ch; returns s.*
 ******************************************************/
char *strset(char *s, char ch);

#endif
