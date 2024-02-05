/*
   Write a call of printf that prints
   1 widget
   if the widget variable (of type int) has the value 1, and
   n widgets 
   otherwise, where n is the value of widget, You are not allowed to 
   use the if statement or any other statement; the answer must be a single
   call of printf
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int widget;
	srand((unsigned int) time(NULL));

	widget = rand() % 8 + 1;
	printf(widget > 1 ? "%d wigets\n" : "%d wiget\n", widget);
	return 0;
}

