#include <stdio.h>

int main(void) {
	FILE *fp;
	int i;

	fp = fopen("temp", "r");

	while (fscanf(fp, "%d", &i))
		printf("%d ", i);

	fclose(fp);
}
