#include <stdio.h>
#include <stdlib.h> // system()
#include <ctype.h>  // toupper()

#define SIZE(arr) (int) (sizeof(arr) / sizeof(arr[0]))
#define CHAR_INDEX grade[i] - 'A'


float compute_GPA(char grade[], int n);


int main(void) {
	char grade[6];

	printf("Enter 6 grade to evaluate GPA: ");
	for (int i = 0; i < SIZE(grade); ++i)
		grade[i] = toupper(getchar());
	getchar();

	printf("GPA: %g\n", compute_GPA(grade, SIZE(grade)));

	system("pause");
	return 0;
}

float compute_GPA(char grade[], int n) {
	int total = 0;
	int conversion[6] = {4, 3, 2, 1, 0, 0};
	for (int i = 0; i < n; ++i) {
		if (CHAR_INDEX >= 0 && CHAR_INDEX <= 5 && CHAR_INDEX != 4)
			total += conversion[grade[i] - 'A'];
		else {
			printf("Error: Grade out of range.\n");
			return -1;
		}
	}
	return (float) total / n;
}



