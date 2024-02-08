// Copies a file

#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

int main(int argc, char **argv) {
	FILE *source, *destination;
	char str_block[BLOCK];
	int reads;

	if (argc != 3) {
		fprintf(stderr, "Usage: $fcopy {source_file} {destination_file}\n");
		exit(EXIT_FAILURE);
	}

	source = fopen(argv[1], "rb");
	destination = fopen(argv[2], "wb");

	if (source == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (destination == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(source); // Subtle to remember, But important.
		exit(EXIT_FAILURE);
	}


	while ((reads = fread(str_block, 1, BLOCK, source)) > 0)
		fwrite(str_block, 1, reads, destination);

	fclose(source);
	fclose(destination);

	return 0;
}
