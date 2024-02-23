/* Write a program entab that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing. Use the same
 * tabstops  as for detab. When either a tab or a single blank would suffice
 * to reach a tabstop, which should be given preference?
 */

#include <stdio.h>

#define TAPSTOP 8
#define NEXT 1

int main(void) {
	int ch, num_blank, num_tab, pos;

	num_blank = num_tab = 0;

	for (pos = 0; (ch = getchar()) != EOF; pos++) {
		if (ch == ' ') {
			// Buffer ' ' and '\t'
			if ((pos + NEXT) % TAPSTOP != 0)
				num_blank++;
			else {
				num_blank = 0;
				num_tab++;
			}
		} else {
			// Flush '\t' --------------------------
			for (;num_tab > 0; num_tab--)
				putchar('\t');

			// Flush ' '
			if (ch == '\t') {
				num_blank = 0; // \t automatically takes blanks into account.
				pos += TAPSTOP - (pos % TAPSTOP) - NEXT;
			}
			else
				for (; num_blank > 0; num_blank--)
					putchar(' ');
			//--------------------------------------

			putchar(ch);
			
			if (ch == '\n')
				pos = 0 - NEXT;
		}
	}

	return 0;
}
