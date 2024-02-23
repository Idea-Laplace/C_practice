/* Write a program to check a C program for rudimentary syntax
 * erros like unbalanced parentheses, brackets and braces. Don`t
 * forget about quotes, both single and double, escape sequences,
 * and comments. (This program is hard if you do it in full gen-
 * -erality.) */

// Quotes in form of /**/ are only considered.
#include <stdio.h>

#define SPACE 100

/* Overall */
void syntax_check(int ch);

/* Parentheses groups */
void parentheses_handling(int ch);
void curly_braces_handling(int ch);
void braces_handling(int ch);

/* Comments and quotes */
void comments_handling(int ch);
void quotes_handling(int ch);

/* Check syntax error */
int syntax_error = 0;

/* main */
int main(void) {
	int ch, valid_syntax;
	int test_array[100] = {0};

	while ((ch = getchar()) != EOF && syntax_error == 0)
		syntax_check(ch);

	if (syntax_error != 0)
		putchar('1');
	else
		putchar('0');
	putchar('\n');

	return 0;
}

void syntax_check(int ch) {
	int braces, curly_braces, parentheses;

	braces = (ch == '[') || (ch == ']');
	curly_braces = (ch == '{') || (ch == '}');
	parentheses = (ch == '(') || (ch == ')');

	if (ch == '"' || ch == '\'')
		quotes_handling(ch);
	else if (ch == '/')
		comments_handling(ch);
	else if (braces)
		braces_handling(ch);
	else if (curly_braces)
		curly_braces_handling(ch);
	else if (parentheses)
		parentheses_handling(ch);
}


/* Precedence : comment == quotes > parenthese group. */

void quotes_handling(int ch) {
	int pair;

	while ((pair = getchar()) != EOF && pair != ch)
		/* Ignore escape sequence */
		if (pair == '\\')
			getchar();

	if (pair == EOF)
		syntax_error = -1;
}

void comments_handling(int ch) {
	int lagging_ch = '\0';

	if ((ch = getchar()) == '*') {
		while ((ch = getchar()) != '/' && ch != EOF && lagging_ch != '*')
			lagging_ch = ch;
		if (ch == EOF)
			syntax_error = -1;
	} else if (ch == '/')
		comments_handling(ch);
}


void parentheses_handling(int ch) {
	if (ch == ')') {
		syntax_error = -1;
		return ;
	}

	while ((ch = getchar()) != EOF && ch != ')') {
		if (ch == '"' || ch == '\'')
			quotes_handling(ch);
		else if (ch == '/')
			comments_handling(ch);
		else if (ch == '(')
			parentheses_handling(ch);
		else if (ch == '{' || ch == '}')
			curly_braces_handling(ch);
		else if (ch == '[' || ch == ']')
			braces_handling(ch);
	}
	if (ch == EOF)
		syntax_error = -1;
}

void braces_handling(int ch) {
	if (ch == ']') {
		syntax_error = -1;
		return ;
	}

	while ((ch = getchar()) != EOF && ch != ']') {
		if (ch == '"' || ch == '\'')
			quotes_handling(ch);
		else if (ch == '/')
			comments_handling(ch);
		else if (ch == '(' || ch == ')')
			parentheses_handling(ch);
		else if (ch == '{' || ch == '}')
			curly_braces_handling(ch);
		else if (ch == '[')
			braces_handling(ch);
	}
	if (ch == EOF)
		syntax_error = -1;
}

void curly_braces_handling(int ch) {
	if (ch == '}') {
		syntax_error = -1;
		return ;
	}

	while ((ch = getchar()) != EOF && ch != '}') {
		if (ch == '"' || ch == '\'')
			quotes_handling(ch);
		else if (ch == '/')
			comments_handling(ch);
		else if (ch == '(' || ch == ')')
			parentheses_handling(ch);
		else if (ch == '{')
			curly_braces_handling(ch);
		else if (ch == '[' || ch == ']')
			braces_handling(ch);
	}
	if (ch == EOF)
		syntax_error = -1;
}
