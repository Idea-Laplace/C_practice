#include <stdio.h>

#define LEN 100


int main(void) {
	int idx_p = 0, idx_s = 0;
	int *product;
	struct {
		int progresses[LEN];
		int speeds[LEN];
		int len;
	} release;

	do {
		scanf("%d", release.progresses + idx_p++);
	} while (getchar() != '\n');

	do {
		scanf("%d", release.speeds + idx_s++);
	} while (getchar() != '\n');

	release.len = idx_s;

	product = release.progresses;
	for (;;) {
		int release_count = 0;
		while (*product >= 100 && (product - release.progresses) < release.len) {
			product++;
			release_count++;
		}

		if (release_count) {
			printf("%d", release_count);
			if ((product - release.progresses) < release.len)
				printf(", ");
			else {
				printf("\n");
				break;
			}
		}

		for (int i = 0; i < release.len; i++)
			release.progresses[i] += release.speeds[i];
	}

	return 0;
}

	

