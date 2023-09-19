/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro
#define LEN 100

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
int strcmp(char *s, char *t);
int strcmp_p(char *s, char *t);
int read_line(char str[], int n);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char s1[LEN + 1];
		char s2[LEN + 1];
		read_line(s1, LEN);
		read_line(s2, LEN);

		printf("strcmp: %d\n", strcmp(s1, s2));
		printf("strcmp_p: %d\n", strcmp_p(s1, s2));

		// Loop decision
		loop_decision(&loop);
	}
	system("pause");
	return 0;
}

// Function(s)
void loop_decision(bool *loop){
	int reply;
	do {
		printf("Loop this program?(y/n): ");
		reply = toupper(getchar());
		while (getchar() != '\n');
		switch (reply){
			case 'Y': printf("\n===================================\n"); break;
			case 'N': printf("\n===================================\n");
					  printf("Program terminated.\n");
					  *loop = false;
					  break;
			default : printf("Type y[Y] or n[N] on the first input.\n"); break;
		}
	} while (reply != 'Y' && reply != 'N');
}

int strcmp(char *s, char *t){
	int i;
	for (i = 0; s[i] == t[i]; ++i){
		if (!s[i])
			return 0;
	}
	return s[i] - t[i];
}
int strcmp_p(char *s, char *t){
	int i;
	for (i = 0; *(s+i) == *(t+i); ++i){
		if (!*(s+i))
			return 0;
	}
	return *(s + i) - *(t + i);
}

int read_line(char str[], int n){
	int ch;
	char *p;
	printf("Enter a sentence: ");
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	if (p - str >= n)
		while (getchar() != '\n');
	return (int) (p - str);
}
