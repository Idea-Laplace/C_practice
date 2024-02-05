/* Write a program that displacys the contents of a file a byte
   and as characters. Have the user sepcify file name on the command line.
   
   Each line shows 10 bytes from the file, as hexadecimal numbers and
   characters. The number in the Offset column indicates the position
   within the file of the first byte on the line. Only printing characters
   (as determined by the isprint function) are displayed; other characters
   are shown as periods. Note that the appearance of a text file may vary,
   depending on the character set and the operating system. The example
   above assume that pun.c is a Windows file, so 0D and 0A bytes (The
   ASCII carriage return and line-feed characters) appear at the end
   of each line. Hint: Be sureto open the file in "rb" mode. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE 10

typedef unsigned char BYTE;

int main(int argc, char **argv) {
	FILE *fp;
	int i, store, ch;
	int offset = 0;
	BYTE buffer[LINE + 1] = {'\0'};

	if (argc != 2) {
		fprintf(stderr, "Usage: $./p06_22 {filename}\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "File %s cannot by opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Offset              Bytes               Characters\n");
	printf("------  -----------------------------  ----------\n");

	for (offset = 0;; offset += 10) {
		store = fread(buffer, sizeof(BYTE), LINE, fp);
		// When fread reads no input, such as EOF.
		if (store == 0) break;

		printf("%6d  ", offset);

		// How tricky!------------------
		for (i = 0; i < store; i++)
			printf("%3.2X", buffer[i]);

		for (; i < 10; i++)
			printf("   ");
		printf("  ");
		// -----------------------------

		for (i = 0; i < store; i++) {
			if (!isprint(buffer[i]))
				buffer[i] = '.';
			printf("%c", buffer[i]);
		}
		printf("\n");
	}

	fclose(fp);

	return 0;
}
