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
#define TEST_URL "https://www.knking.com/index.html"

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
int read_line(char str[], int n);
void remove_filename(char *url);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char url[] = TEST_URL;
		puts(url);
		remove_filename(url);
		printf("URL the filename reomoved: %s\n", url);

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

void remove_filename(char *url){
	char *p = url + strlen(url);
	while (*p != '/' && p > url)   // In the case of wrong input
		--p;
	*p = '\0';
}
