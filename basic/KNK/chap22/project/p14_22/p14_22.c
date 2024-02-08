#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: $p14_22 {filename}\n");
		exit(EXIT_FAILURE);
	}
	
	FILE *fp_read, *fp_write;
	char *extension;
	int ch, shift;

	fp_read = fopen(argv[1], "r");

	if (fp_read == NULL) {
		fprintf(stderr, "Error, file %s can't be read.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	extension = malloc(strlen(argv[1]) + strlen(".enc")  + 1);
	if (extension == NULL) {
		fprintf(stderr, "Error, filename memory issue.\n");
		exit(EXIT_FAILURE);
	}
	strcpy(extension, argv[1]);
	strcat(extension, ".enc");

	fp_write = fopen(extension, "w");

	if (fp_write == NULL) {
		fprintf(stderr, "Error, file %s can't be created.\n", extension);
		exit(EXIT_FAILURE);
	}

	printf("Enter shift amount(1-25): ");
	scanf("%d", &shift);
	while (getchar() != '\n');

	if (shift > 25 || shift < 1) {
		printf("Shift out of range, scaled.\n");
		shift %= 26;
		if (shift < 0)
			shift += 26;
		printf("Scaled shift: %d\n", shift);
	}

	while ((ch = fgetc(fp_read)) != EOF) {
		if (isupper(ch))
			fputc(((ch + shift - 'A') % 26 + 'A'), fp_write);
		else if (islower(ch))
			fputc(((ch + shift - 'a') % 26 + 'a'), fp_write);
		else
			fputc(ch, fp_write);
	}

	printf("Encrypted file %s created.\n", extension);
	fclose(fp_write);
	fclose(fp_read);

	return 0;
}
