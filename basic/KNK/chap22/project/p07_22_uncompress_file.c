/* Of the many techniques for compressing the contents of a file,
   one of the simplest is known as run-length encoding. This technique
   compresses a file by replacing sequences of identical bytes by 
   a pair of bytes: a repetition count followed by a byte to be
   repeated. For example, suppose that the file to by compressed
   begins with the following sequence of bytes(shown in hexadecimal):

   46 6F 20 62 61 72 21 21 20 20 20 20 20
   
   The compressed file will contain the following bytes:
   
   01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20

   Run length encoding works well if the original file contains
   many long sequences fo identical bytes. In the worst case (A
   file with no repeated bytes.), run length encoding can actually
   double the length of the file.

   (a) Write a program named compress_file that uses run-length
       encoding to compress a file. To run compress_file, we'd
	   use a command of the form
	   $./compress_file original_file
	   compress_file will return the compressed version of original
	   file to original_file.rle.

   (b) Write a program named uncompress_file that reverses the
       compression performed by the compress_file program. The
	   uncompress_file command will have the form
	   $./uncompress_file foo.txt.rle
	   will cause uncompress)file to open the file and write an 
	   uncompressed version of its contents to foo.txt.
	   uncompress_file should play an error message if its command line
	   argument doesn't end with the .rle extension.    */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	FILE *fp_to_uncompress;
	FILE *fp_uncompressed;
	int ch;
	int extension;
	char *file_len;

	struct {
		unsigned char top;
		unsigned char byte;
	} pseudo_stack;


	// Error handling -------------------------------------------
	if (argc != 2) {
		fprintf(stderr, "Usage: $./uncompress_file {filename1}\n");
		exit(EXIT_FAILURE);
	}

	exetension = strlen(argv[1]) - strlen(".rle");
	if (strlen(argv[1]) < strlen(".rle")) {
		fprintf(stderr, "File extension not matched.\n");
		exit(EXIT_FAILURE);
	}
	else if (strcmp(argv[1] + extension, ".rle")) {
		fprintf(stderr, "File extension not matched.\n");
		exit(EXIT_FAILURE);
	}

	if ((fp_original = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "File %s cannot be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((file_len = malloc(strlen(argv[1]))) == NULL) {
		fprintf(stderr, "Filename for compressed file cannot be created.\n");
		exit(EXIT_FAILURE);
	}

	strncpy(file_len, argv[1]);

	if ((fp_compressed = fopen(file_len, "wb")) == NULL) {
		fprintf(stderr, "Compression cannot be initiated.\n");
		exit(EXIT_FAILURE);
	}
	// ----------------------------------------------------------

	pseudo_stack.top = 0;
	while ((ch = fgetc(fp_original)) != EOF) {
		if (ch == pseudo_stack.byte || pseudo_stack.top == 0) {
			pseudo_stack.byte = ch;
			pseudo_stack.top++;
		}
		else {
			fputc(pseudo_stack.top, fp_compressed);
			fputc(pseudo_stack.byte, fp_compressed);
			pseudo_stack.byte = ch;
			pseudo_stack.top = 1;
		}
	}
	
	if (pseudo_stack.top) {
		fputc(pseudo_stack.top, fp_compressed);
		fputc(pseudo_stack.byte, fp_compressed);
	}

	fclose(fp_original);
	fclose(fp_compressed);

	return 0;
}
