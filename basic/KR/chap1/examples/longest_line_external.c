#include <stdio.h>

#define MAXLINE 1000  // maximum input line size.
#define LINEFEED 1    // space for a linefeed character.

// External variables
int max;								// Maximum length seen so far.
char line[MAXLINE + LINEFEED + 1];      // Current input line.
char longest[MAXLINE + LINEFEED + 1];   // Longest lin saved here.

// Prototypes
int my_getline(void);
void copy(void);

/* main: print longest input line; specialized version */
int main(void) {
	int len;
	extern int max;         // extern is not necessary unless
	extern char longest[];  // there exists a local variable of same name.

	max = 0;
	while ((len = my_getline()) > 0)
		if (len > max) {
			max = len;
			copy();
		}

	if (max > 0)   // If there was a line.
		printf("%s", longest);

	return 0;
}

// my_getline: specialized version.
int my_getline(void) {
	int ch, i;
	extern char line[];  // extern is not necessary.

	for (i = 0; i < MAXLINE && (ch = getchar()) != EOF && ch != '\n'; i++)
		line[i] = ch;
	if (ch == '\n') {
		line[i++] = ch;
		line[i] = '\0';
	} else {
		line[i] = '\n';
		line[i + 1] = '\0';
	}

	return i;
}

// copy: specialized version.
void copy(void) {
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}
	

