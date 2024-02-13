/*
   Repeat Exercise 4, this tim using the UTF-8 multibyte encoding.
   For example, the phrase dejavu could be represented by the string
   "d\xc3\xa9j\xc3\xa0 vu"
*/

// a\: e00, e\:e08, e^:e0a, e/:e09, i^:e0e, o^:f04, u^:f0b 
#include <stdio.h>


int main(void) {
	// To avoid hex escape sequence out of range, spliting literal is applied.
	printf("C\xc3\xb4""te d'Azur\n");
	printf("cr\xc3\xa8""me br\xc3\xbb""l\xc3\xa9""e\n");
	printf("cr\xc3\xa8""me fra\xc3\xae""che\n");
	printf("Fahrvergn\xc3\xbc""gen\n");
	printf("t\xc3\xaa""te-\xc3\xa0""-t\xc3\xaa""te\n");

	return 0;
}
