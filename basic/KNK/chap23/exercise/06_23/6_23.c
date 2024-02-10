/*
	K. N. King C programming 2nd edition chapter23 exercise 6, p.624

	In each of the following cases, indicate which function would be the best to use:
			memcpy, memmove, strcpy or strncpy. 
	Assume that the indicated action is to be performed by a single function call.

	(a) Moving all elements of an array "down" one position in order to leave room
		for a new element in position 0.

	(b) Deleting the first character in a null-terminated string by moving all other
		characters back in one position.
		
	(c) Copying a string into a character array that may not be large enough to hold it.
		If the array is too small, assume that the string is to be truncated; no null
		character is necessary at the end.

	(d) Copying the contents of one array variable into another.
*/

#include <stdio.h>
#include <string.h>

#define LEN 20


int main(void) {
	char test_str[LEN + 1] = "test string";
	char dest_str[LEN + 1];

	printf("Initial string: %s\n", test_str);

	// (a): memmove, since data overlap happens.
	memmove(test_str + 1, test_str, sizeof(test_str));
	test_str[0] = '!';
	printf("Process (a): %s\n", test_str);

	// (b): memmove, since strcpy is undefined for memory overlaps.
	// A pitfall!
	memmove(test_str, test_str + 1, sizeof(test_str));
	printf("Process (b): %s\n", test_str);

	// (c): strncpy, no null character is necessary at the end.
	strncpy(test_str, "Nice to meet you sir! I've heard of you.", sizeof(test_str) - 1);
	test_str[LEN] = '\0';
	printf("Process (c): %s\n", test_str);

	// (d): memcpy, no other condition(no necessary null character.)
	memcpy(dest_str, test_str, strlen(test_str) + 1);
	printf("Process (d): %s\n", dest_str);

	return 0;
}
