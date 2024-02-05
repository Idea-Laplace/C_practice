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
	char *file_name;
	
	enum {REPETITION = 0, BYTE = 1};
	struct {
		int status;
		char pair[2];
	} byte_buff;


	// Error handling -------------------------------------------
	if (argc != 2) {
		fprintf(stderr, "Usage: $./uncompress_file {filename1}\n");
		exit(EXIT_FAILURE);
	}

	extension = strlen(argv[1]) - strlen(".rle");
	if (strcmp(argv[1] + extension, ".rle")) {
		fprintf(stderr, "File extension not matched.\n");
		exit(EXIT_FAILURE);
	}

	if ((fp_to_uncompress = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "File %s cannot be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((file_name = malloc(strlen(argv[1]) + 10)) == NULL) {
		fprintf(stderr, "Filename for compressed file cannot be created.\n");
		exit(EXIT_FAILURE);
	}

	strncpy(file_name, argv[1], extension);
	strcat(file_name, ".uncompress");


	if ((fp_uncompressed = fopen(file_name, "wb")) == NULL) {
		fprintf(stderr, "Compression cannot be initiated.\n");
		exit(EXIT_FAILURE);
	}

	free(file_name);
	// ----------------------------------------------------------

	byte_buff.status = REPETITION;
	while ((ch = fgetc(fp_to_uncompress)) != EOF) {
		if (byte_buff.status == REPETITION) {
			(byte_buff.pair)[REPETITION] = ch;
			byte_buff.status = BYTE;
		}

		else if (byte_buff.status == BYTE) {
			(byte_buff.pair)[BYTE] = ch;
			byte_buff.status = REPETITION;
			for (int i = 0; i < (byte_buff.pair)[REPETITION]; i++)
				fputc((byte_buff.pair)[BYTE], fp_uncompressed);
		}
	}

	fclose(fp_to_uncompress);
	fclose(fp_uncompressed);

	return 0;
}
