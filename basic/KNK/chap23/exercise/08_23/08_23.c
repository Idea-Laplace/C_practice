/* 
  Use strchr to write the following function:
  int numchar(const char *s, char ch);

  numchar returns the number of times the character
  ch occurs in the string s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numchar(const char *s, char ch);

int main(int argc, char **argv) {
	int ch, num;
	if (argc != 2) {
		fprintf(stderr, "Usage: $./p8_23 {string}\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter a character you want to count: ");
	ch = getchar();
	while (getchar() != '\n');
	
	num = numchar(argv[1], ch);
	printf("Number of %c in %s: %d\n", ch, argv[1], num);
	return 0;
}

int numchar(const char *s, char ch) {
	char *p;
	int count = 0;

	if ((p = strchr(s, ch)) == NULL) 
		return count;
	count++;

	while ((p = strchr(p + 1, ch)) != NULL)
		count++;

	return count;
}


