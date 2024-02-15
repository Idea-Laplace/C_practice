/*
   Write programs that display the current date and time
   in each of the following formats. Use strftime to do
   all or most of formatting.

   (a) Sunday, June 3, 2007 05:48p
   (b) Sun, 3 Jun 07, 17:48
   (c) 06/03/07/ 5:48/34 PM
*/

#include <stdio.h>
#include <time.h>

#define LEN 100

int main(void) {
	char str1[LEN], str2[LEN], str3[LEN];
	char am_or_pm;
	time_t current = time(NULL);
	struct tm *current_tm;

	current_tm = localtime(&current);

	// (a) ----------------------------------------------------------
	strftime(str1, sizeof(str1), "%A, %B %d, %Y %I:%M", current_tm);
	if (current_tm->tm_hour / 12)
		am_or_pm = 'p';
	else
		am_or_pm = 'a';

	printf("%s%c\n", str1, am_or_pm);
	// --------------------------------------------------------------
	puts("");
	// (b) ----------------------------------------------------------
	strftime(str2, sizeof(str2), "%a, %d %b %y %H:%M", current_tm);
	printf("%s\n", str2);
	// --------------------------------------------------------------
	puts("");
	// (c) ----------------------------------------------------------
	strftime(str3, sizeof(str3), "%m/%d/%y %I:%M:%S%p", current_tm);
	printf("%s\n", str3);
	// --------------------------------------------------------------

	return 0;
}



	

