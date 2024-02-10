/*
   Write a program that prompts the user to enter a series of words
   separated by single spaces, then prints the words in reverse order.
   Read the input as a string, and then use strtok to break into words.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

char *read_string(FILE *fp);
char **add_word(char **words, char *word, int count_word);
void free_words(char **words);

int main(void) {
	char **words;
	char *word_string, *p;
	int count_word = 0;

	words = malloc(sizeof(char *) * LEN);
	word_string = malloc(sizeof(char) * LEN);

	if (words == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	if (word_string == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		free(words);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < LEN; i++)
		words[i] = NULL;

	printf("Enter a series of words separated by white characters.\n");
	word_string = read_string(stdin);

	p = strtok(word_string, " \t\n");
	while (p != NULL) {
		words = add_word(words, p, count_word);
		if (words == NULL) {
			free(word_string);
			fprintf(stderr, "Cannot add word\n");
			exit(EXIT_FAILURE);
		}
		count_word++;
		p = strtok(NULL, " \n\t");
	}

	printf("In reverse word order: \n");
	for (int i = count_word - 1; i >= 0; i--)
		printf("%s ", words[i]);
	printf("\n");

			
	free(words);
	free(word_string);

	return 0;
}

char *read_string(FILE *fp) {
	char *s;
	int ch, full = LEN, idx = 0;

	if ((s = malloc(full + 1)) == NULL) {
		fprintf(stderr, "Cannot store the series of words, memory issue.\n");
		return NULL;
	}

	while ((ch = getc(fp)) != EOF && ch != '\n') {
		if (idx >= full) {
			full *= 2;
			char *re_s;
			re_s = realloc(s, full + 1);
			if (re_s == NULL) {
				fprintf(stderr, "Too many words, memory issue.\n");
				free(s);
				return NULL;
			}
			s = re_s;
		}
		*(s + idx++) = ch;
	}

	// getchar doesn't add null character automatically.
	// contrary to scanf("%s") or gets, fgets.
	*(s + idx) = '\0';

	return s;
}

		
char **add_word(char **words, char *word, int count_word) {
	char **temp;
	int full = LEN;

	if (full <= count_word) {
		full *= 2;
		temp = realloc(words, full * sizeof(char *));
		if (temp == NULL) {
			free(words);
			return NULL;
		}
		words = temp;
	}
	words[count_word] = word;
	return words;
}

