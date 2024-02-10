/*
   Write a program that counts the number of sentences in a text file
   (obtained from standard input). Assume that each sentencs ends with
   a  .,? or ! followed by a white-space character(including '\n').
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	bool in_sentence = false;
	int ch;
	int sentence_count = 0;

	while ((ch = getchar()) != EOF) {
		if (strchr("!?.", ch) != NULL) {
			if (in_sentence) {
				sentence_count++;
				in_sentence = false;
			}
			else
				continue;
		} else if (!isspace(ch))
			in_sentence = true;
	}

	printf("Number of sentences: %d\n", sentence_count);
	return 0;
}
	
	



