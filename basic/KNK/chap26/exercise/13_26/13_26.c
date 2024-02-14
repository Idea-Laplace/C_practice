/*
   Section 26.3 described some of the ISO 8601 date and time formats.
   Here are a few more:
   (a) Year followed by day of year:  YYYY-DDD, where DDD is a number
       between 001 and 366
   (b) Year, week, and day of week: YYYY-Www-D, where ww is a number
       between 01 and 53, and D is a digit between 1 through 7, beginning
	   with Monday and ending with Sunday.
   (c) Combined date and time: YYYY-MM-DDThh:mm:ss

   Give strftime string that correspoding to each of these formats.
*/


#include <stdio.h>
#include <time.h>

int main(void) {
	char datetime[21];
	time_t current = time(NULL);

	printf("(a) YYYY-DDD:\n");
	strftime(datetime, sizeof(datetime), "%Y-%j", localtime(&current));
	printf("%s\n", datetime);
	printf("(b) YYYY-Www-D:\n");
	strftime(datetime, sizeof(datetime), "%Y-%W-%w", localtime(&current));
	printf("%s\n", datetime);
	printf("(c) YYYY-MM-DDThh:mm:ss:\n");
	strftime(datetime, sizeof(datetime), "%Y-%m-%d %T", localtime(&current));
	printf("%s\n", datetime);

	return 0;
}
