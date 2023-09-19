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
#define MAX_LEN 50
#define ALPHABET 26
// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);
bool are_anagrams(const char *word1, const char *word2);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char word1[MAX_LEN + 1], word2[MAX_LEN + 1];
		printf("Enter a word: ");
		read_line(word1, MAX_LEN);
		printf("Enter another word: ");
		read_line(word2, MAX_LEN);
		printf("These words are%sanagrams.\n", are_anagrams(word1, word2) ? " " : " not ");

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

bool are_anagrams(const char *word1, const char *word2) {
	int alphabet_count[ALPHABET] = {0};
	int index;
	while (*word1) {
		if (isalpha(*word1)) {
			index = toupper(*word1) - 'A';
			alphabet_count[index]++;
		}
		++word1;
	}
	while (*word2) {
		if (isalpha(*word2)) {
			index = toupper(*word2) - 'A';
			alphabet_count[index]--;
		}
		++word2;
	}
	for (int i = 0; i < ALPHABET; ++i)
		if (alphabet_count[i])
			return false;
	return true;
}

