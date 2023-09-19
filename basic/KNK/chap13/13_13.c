/************************************************
 * 13-13                                        *
 * void build_index_url(const char *, char *)   *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define PREFIX "https://www."
#define POSTFIX "/index.html"
#define SAMPLE "knking.com"
#define LEN 1000

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
int read_line(char str[], int n);
void build_index_url(const char *domain, char *index_url);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char index_url[LEN + 1];
		build_index_url(SAMPLE, index_url);
		printf("knking.com\n");
		puts(index_url);

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

int read_line(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}

void build_index_url(const char *domain, char *index_url){
	strcat(strcat(strcpy(index_url, PREFIX), domain), POSTFIX);
}
