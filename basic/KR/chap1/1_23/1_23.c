/* Write a program to remove all comments from a C program.
 * Don`t forget to handle quoted strings and character constants
 * properly. C comments do not nest.
 */

// Header
#include <stdio.h>

void rcomment(int ch);
void in_comment(void);
void echo_quote(int ch);

int main(void) {
	int ch;

	while ((ch = getchar()) != EOF)
		rcomment(ch);
	return 0;
}

void rcomment(int ch) {
	int ch_next;

	if (ch == '/') {
		if ((ch_next = getchar()) == '*')
			in_comment();
		else if (ch_next == '/') {
			putchar(ch);
			rcomment(ch_next);
		} else {
			putchar(ch);
			putchar(ch_next);
		}
	} else if (ch == '\'' || ch == '"')
		echo_quote(ch);
	else 
		putchar(ch);
}

void in_comment(void) {
	int ch, ch_lag;
	ch_lag = getchar();
	ch = getchar();
	while (ch_lag != '*' || ch != '/') {
		ch_lag = ch;
		ch = getchar();
	}
}

void echo_quote(int ch) {
	int ch_next;

	putchar(ch);
	while((ch_next = getchar()) != ch) {
		putchar(ch_next);
		if (ch_next == '\\')  /* ignore escape sequence \" or \'. */
			putchar(getchar());
	}
	putchar(ch_next);
}
