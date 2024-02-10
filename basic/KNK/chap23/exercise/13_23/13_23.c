#include <stdio.h>
#include <string.h>

/*
   Use strtok to write the following function:
   int count_words(char *sentence);
   count_words returns the number of words in the string sentence, 
   where a 'word' is any sequence of non-white characters. count_words
   is allowed to modify the string.
*/

int count_words(char *sentence);

int main(void) {
	char sentence[50] = "Hello, my name is Han, Jun hui.";
	printf("Words in '%s': ", sentence);
	printf("%d\n", count_words(sentence));
	return 0;
}

int count_words(char *sentence) {
	char *p;
	int count = 0;

	p = strtok(sentence, "\t ");
	if (p == NULL)
		return count;
	else
		count++;

	while ((p = strtok(NULL, " \t")) != NULL)
		count++;

	return count;
}
