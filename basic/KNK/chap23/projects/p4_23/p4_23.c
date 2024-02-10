/*
   Write a program that prompts the user to enter a series of words
   separated by single spaces, then prints the words in reverse order.
   Read the input as a string, and then use strtok to break into words.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

struct node {
	char *word;
	struct node *next;
};

char *read_string(FILE *fp);
struct node *insert_word(char *s, struct node *top);
void print_word_stack(struct node *);
void free_stack(struct node *top);

int main(void) {
	struct node *word_stack = NULL, *temp;
	char *words;
	char *p;

	printf("Enter a series of words separated by white characters.\n");
	words = read_string(stdin);
	p = strtok(words, " \t\n");
	if (p == NULL) {
		fprintf(stderr, "No valid words input.\n");
		exit(EXIT_FAILURE);
	}

	while (p != NULL) {
		temp = insert_word(p, word_stack);
		if (temp == NULL) {
			free_stack(word_stack);
			fprintf(stderr, "Error in insert.\n");
			exit(EXIT_FAILURE);
		}
		word_stack = temp;
		
		p = strtok(NULL, " \n\t");
	}

	printf("In reverse word order: \n");
	print_word_stack(word_stack);

	free_stack(word_stack);
	free(words);

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

		
struct node *insert_word(char *s, struct node *top) {
	struct node *new_node;
	new_node = malloc(sizeof(*new_node));

	if (new_node == NULL) {
		fprintf(stderr, "Cannot add word in a user stack, memory issue.\n");
		return NULL;
	}

	new_node->word = s;
	new_node->next = top;
	return new_node;
}

void print_word_stack(struct node *top) {
	while (top != NULL) {
		printf("%s ", top->word);
		top = top->next;
	}
	printf("\n");
}

void free_stack(struct node *top) {
	struct node *lead, *lag;
	lead = lag = top;

	while (lead != NULL) {
		lead = lead->next;
		free(lag);
		lag = lead;
	}
}


