#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *fp_data;
	int phone_number[3];
	int ch;
	int input;

	if (argc != 2) {
		fprintf(stderr, "Usage: $standard {filename}\n");
		exit(EXIT_FAILURE);
	}

	fp_data = fopen(argv[1], "r");
	if (fp_data == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (;;) {
		ch = fgetc(fp_data);
		ungetc(ch, fp_data);
		if (!isdigit(ch))
			input = fscanf(fp_data, "%*[^0-9]%3d", &phone_number[0]);
		else
			input = fscanf(fp_data, "%3d", &phone_number[0]);
		
		ch = fgetc(fp_data);
		ungetc(ch, fp_data);
		if (!isdigit(ch))
			input = fscanf(fp_data, "%*[^0-9]%3d", &phone_number[1]);
		else
			input = fscanf(fp_data, "%3d", &phone_number[1]);

		ch = fgetc(fp_data);
		ungetc(ch, fp_data);
		if (!isdigit(ch))
			input = fscanf(fp_data, "%*[^0-9]%4d", &phone_number[2]);
		else
			input = fscanf(fp_data, "%4d", &phone_number[2]);
		
		if (input == EOF) break;
		printf("(%.3d) %.3d-%.4d\n", phone_number[0], phone_number[1], phone_number[2]);
	}

	fclose(fp_data);
	return 0;
}
