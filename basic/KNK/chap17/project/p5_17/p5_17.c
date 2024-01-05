#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./readline/readline.h"

#define MAX_WORD 20

struct words {
	char word[MAX_WORD + 1];
	struct words *next;
};

void insert(struct words **chain_pointer, char *word);

int main(void) {
	struct words *chain = NULL;
	struct words *p;
	char word[MAX_WORD + 1];

	for (;;) {
		printf("Enter word: ");
		readline(word, MAX_WORD);
		if (*word == '\0') break;
		insert(&chain, word);
	}

	printf("In sorted order: ");
	for (p = chain; p != NULL; p = p->next)
		printf("%s ", p->word);
	printf("\n");

	return 0;
}

void insert(struct words **chain_pointer, char *word) {
	struct words *new_word = malloc(sizeof(*new_word));
	struct words *cur, *prev;

	if (new_word == NULL) {
		printf("Cannot add word, memory issue.\n");
		return;
	}

	*new_word->word = '\0';
	new_word->next = NULL;
	strcpy(new_word->word, word);

	for (cur = *chain_pointer, prev = NULL;
		cur != NULL && strcmp(new_word->word, cur->word) > 0;
		prev = cur, cur = cur->next);

	if (prev == NULL) {
		*chain_pointer = new_word;
	}
	else {
		prev->next = new_word;
		new_word->next = cur;
	}
}