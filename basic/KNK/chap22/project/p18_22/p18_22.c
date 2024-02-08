#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

void quick_sort(int *arr, int len);

int main(int argc, char **argv) {
	FILE *fp;
	int numbers[MAX], element, median;
	int len;

	if (argc != 2) {
		fprintf(stderr, "Error: Usage> $./p18_22 {filename}.\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%d", &element) != EOF)
		numbers[len++] = element;

	quick_sort(numbers, len);

	if (len == 0) {
		printf("No number exists in file %s.\n", argv[1]);
		return 0;
	}

	median = len % 2 ? numbers[len / 2] : (numbers[len / 2] + numbers[len / 2 - 1]) / 2;

	printf("Number information of file %s.\n", argv[1]);
	printf("Largest number: %d\n", numbers[len - 1]);
	printf("Smallest number: %d\n", numbers[0]);
	printf("Median number: %d\n", median);

	return 0;
}

void quick_sort(int *arr, int len) {
	int *head, *tail, *sep;
	int temp;

	if (len <= 1) return;

	head = arr;
	tail = arr + len - 1;

	for (;;)  {
		temp = *head;

		while (head < tail && *tail >= temp)
			tail--;

		if (head >= tail) {
			sep = tail;
			*sep = temp;
			break;
		} else
			*head++ = *tail;
		
		while (head < tail && *head <= temp)
			head++;

		if (head >= tail) {
			sep = head;
			*sep = temp;
			break;
		} else
			*tail-- = *head;
	}

	quick_sort(arr, (int)(sep - arr));
	quick_sort(sep + 1, (int)(arr + len - sep - 1));
}
