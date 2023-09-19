/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro
#define STRLEN 100
#define LEN_GEN(arr) ((int) sizeof(arr) / sizeof(*arr))
#define CENSOR_WORD "fuck"

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
void censor_foo(char str[], int str_len);
void censor(char str[], int str_len, const char cen[], int cen_len);
int read_line(char str[], int n);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char str[STRLEN + 1];
		char *p = str;
		printf("Enter a sentence: ");
		read_line(str, STRLEN);

		censor(str, STRLEN, CENSOR_WORD, LEN_GEN(CENSOR_WORD));
		while (*p)
			printf("%c", *p++);
		printf("\n");


		

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


void censor_foo(char str[], int str_len){
	for (char *p = str; (p - str) <= str_len - LEN_GEN("foo"); ++p){
		if (*p == 'f' && *(p+1) == 'o' && *(p+2) == 'o'){
			*p++ = 'x';
			*p++ = 'x';
			*p = 'x';
		}
	}
}

void censor(char str[], int str_len, const char cen[], int cen_len){
	for (char *p = str; (p - str) <= str_len - cen_len; ++p){
		bool same = true;
		for (int i = 0; i < cen_len - 1; ++i){      // -1 is for '\0'
			if (*(p+i) != *(cen + i)){
				same = false;
				break;
			}
		}
		if (same){
			for (int i = 0; i < cen_len - 1; ++i)
				*p++ = 'x';
			--p;
		}
	}
}


int read_line(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}
