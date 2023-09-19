#include <stdio.h>
#include <stdlib.h>

#define SIZE (int) (sizeof(arr) / sizeof(arr[0]))

int max(int a[], int n);
float mean(int a[], int n);
int num_positive(int a[], int n);


int main(void) {
	int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, -1, -2};
	printf("%d\n", SIZE);
	printf("Max number in arr: %d\n", max(arr, SIZE));
	printf("Average value of arr: %f\n", mean(arr, SIZE));
	printf("Number of positive numbers in arr: %d\n", num_positive(arr, SIZE));

	system("pause");
	return 0;
}


int max(int a[], int n) {
	int largest = a[0];
	for (int i = 1; i < n; ++i) {
		if (largest < a[i])
			largest = a[i];
	}
	return largest;
}


float mean(int a[], int n) {
	int average = a[0];
	for (int i = 1; i < n; ++i) {
		average += a[i];
	}
	return (float) average / n; //type conversion may rise.
}


int num_positive(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0)
			++count;
	}
	return count;
}
