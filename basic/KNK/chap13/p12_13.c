/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define LOOP_MESSAGE "Loop this program?(y/n): "
#define TERMINATE_MESSAGE "Program terminated.\n"
#define MAX_WORDS 30
#define MAX_WORD_LEN 20
#define MAX_SENTENCE_LEN 1000
// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);
int word_split(char *sentence, char (*store)[MAX_WORD_LEN + 1]);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char sentence[MAX_SENTENCE_LEN + 1];
		char wordwise_store[MAX_WORDS][MAX_WORD_LEN + 1];
		int word_count;
		printf("Enter a sentence: ");
		read_line(sentence, MAX_SENTENCE_LEN);
		word_count = word_split(sentence, wordwise_store);
		for (int i = 0; i < word_count; ++i) {
			printf("Word %2d: %s\n", i + 1, wordwise_store[i]);
		}

		// Loop decision
		loop_decision(&loop, LOOP_MESSAGE, TERMINATE_MESSAGE);
	}
	system("pause");
	return 0;
}

// Function(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message){
	int reply;
	do {
		printf("%s", loop_message);
		reply = toupper(getchar());
		while (getchar() != '\n');
		switch (reply){
			case 'Y': printf("\n===================================\n"); break;
			case 'N': printf("\n===================================\n");
					  printf("%s", terminate_message);
					  *loop = false;
					  break;
			default : printf("Type y[Y] or n[N] on the first input.\n"); break;
		}
	} while (reply != 'Y' && reply != 'N');
}

int read_line(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}

int word_split(char *sentence, char (*store)[MAX_WORD_LEN + 1]) {
	int word_count = 0;
	while (*sentence) {
		if (isspace(*sentence)){
			++sentence;
			continue;
		}
		char *p = sentence;
		while (!isspace(*++p) && *p);
		if (*p) {
			*p = '\0';
			strcpy(*store, sentence);
			++store;
			sentence = ++p;
			++word_count;
		}
		else {
			strcpy(*store, sentence);
			sentence = p;
			++word_count;
		}
	}
	return word_count;
}
