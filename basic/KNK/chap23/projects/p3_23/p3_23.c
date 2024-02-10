/* 
  Write a program that copies a text file from standard input to standard output, 
  capitalizing the first letter in each word.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
	int ch;
	bool in_word = false;

	while ((ch = getchar()) != EOF) {
		if (!isalpha(ch)) {
			putchar(ch);
			in_word = false;
		} else if (!in_word) {
			putchar(toupper(ch));
			in_word = true;
		} else
			putchar(ch);
	}

	return 0;
}

