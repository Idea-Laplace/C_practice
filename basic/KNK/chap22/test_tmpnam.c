#include <stdio.h>
#include <stdlib.h>


int main(void) {
	FILE *fp_normal;
	FILE *fp_temp;

	char filename[L_tmpnam];
	tmpnam(filename);

	fp_normal = fopen("foo", "w");
	fp_temp = fopen(filename, "w");

	if (fp_normal == NULL || fp_temp == NULL) {
		printf("Cannot create files.\n");
		exit(EXIT_FAILURE);
	}

	fclose(fp_normal);
	fclose(fp_temp);

	return 0;
}
