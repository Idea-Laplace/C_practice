/**************************************************************
 * 12-13                                                      *
 * void get_extension(const char *file_name, char *extension);*
 **************************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define FILE_LEN 100
#define EXTEN_LEN 20

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop);
int read_line(char str[], int n);
void get_extension(const char *file_name, char *extension);
bool test_extension(const char *file_name, const char *extension);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char filename[FILE_LEN + 1];
		char extension[EXTEN_LEN + 1];

		printf("Enter a filename: ");
		read_line(filename, FILE_LEN);
		printf("Enter an extension: ");
		read_line(extension, EXTEN_LEN);
		printf("Extension: %s\n", test_extension(filename, extension) ? "True" : "False");


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

void get_extension(const char *file_name, char *extension){
	int i = 0;
	while (i < strlen(file_name) && file_name[i++] != '.');
	strcpy(extension, &file_name[i]);
}

int read_line(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}

bool test_extension(const char *file_name, const char *extension){
	while (*file_name && *file_name++ != '.');
	while (*file_name){
		if (toupper(*file_name++) != toupper(*extension++))
			return false;
	}
	if (*extension)
		return false;

	return true;
}
