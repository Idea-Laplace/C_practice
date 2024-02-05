#include <stdio.h>
#include <stdlib.h>
/*
   Find the error in the following program fragment and show how to fix it.

   FILE *fp;

   if (fp = fopen(filename, "r")) {
       // read characters until end-of-file.
   }
   fclose(fp);
*/

/* 
   fclose cannot close NULL pointer.
   If we are to try, segmentation fault rises.
   so we need additional error handling.
*/

int main(void) {
	FILE *fp;
	if (fp = fopen("test.c", "r"));
	else {
		printf("File cannot be opened.\n");
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	return 0;
}
