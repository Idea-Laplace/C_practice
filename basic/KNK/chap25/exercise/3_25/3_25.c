/*
   One of the useful properties of UTF-8 is that no sequence of bytes within a multibyte
   character can possibly represent another valid multibyte character. Does the Shift-JIS
   encoding for kanji (discussed in Exercise 2) have this property?
*/

// No! UTF-8 encoding have byte sequence of characters start with 0, 110, 1110 or 11110,
// any trailing sequence must start with 10, which prevents any subsequence of multibyte
// character to be a valid character sequence.

// Conversely, Shift-JIS encoding, allows second byte to overlap first 'valid' character.
// For example, any second byte between 0x40-0x7e would be treated as valid single charater
// if no preceding shift sequence byte-from 0x81 to 0x9f- exist.

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>


int main(void) {
	setlocale(LC_ALL, "jp_JP.shift_jis");

	const char *s1 = "\x81\x49";
	const char *s2 = "\x49";



	printf("%s\n", s1);
	printf("%s\n", s2);

	return 0;
}

