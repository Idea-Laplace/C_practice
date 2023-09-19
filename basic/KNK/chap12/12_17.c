/************************************************
 * 12-17
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Macro
#define LEN 50
#define REPEAT 1000

// External Variable(s)

// Prototype(s)
double sum_3d_arr_sub(const double a[][LEN][LEN], int n);
double sum_3d_arr_pointer(const double a[][LEN][LEN], int n);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		srand(time(NULL));
		//Subscript =====================================================================
		clock_t start_sub = clock();
		for (int i = 0; i < REPEAT; ++i){
			double arr[LEN][LEN][LEN];
			for (double *p = arr[0][0]; (p - arr[0][0]) < LEN*LEN*LEN; ++p)
				*p = rand() % 100;

			sum_3d_arr_sub(arr, LEN);
		}
		clock_t end_sub = clock();
		printf("Subscript-nested for: %d^3 matrix, %d times, %lf sec was consumed.\n",\
				LEN, REPEAT, (double) (end_sub - start_sub) / CLOCKS_PER_SEC);
		// ==============================================================================
		clock_t start_pointer = clock();
		for (int i = 0; i < REPEAT; ++i){
			double arr[LEN][LEN][LEN];
			for (double *p = arr[0][0]; (p - arr[0][0]) < LEN*LEN*LEN; ++p)
				*p = rand() % 100;

			sum_3d_arr_pointer(arr, LEN);
		}
		clock_t end_pointer = clock();
		printf("Subscript-nested for: %d^3 matrix, %d times, %lf sec was consumed.\n",\
				LEN, REPEAT, (double) (end_pointer - start_pointer) / CLOCKS_PER_SEC);

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while (getchar() != '\n');
			switch (reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("Program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first input.\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}

// Function(s)
double sum_3d_arr_sub(const double a[][LEN][LEN], int n){
	int i, j, k;
	double sum = 0.0;
	for (i = 0; i < n; ++i)
		for (j = 0; j < LEN; ++j)
			for(k = 0; k < LEN; ++k)
				sum += a[i][j][k];

	return sum;
}

double sum_3d_arr_pointer(const double a[][LEN][LEN], int n){
	double sum = 0.0;
	for (int i = 0; i < n * LEN * LEN; ++i)
		sum += *(a[0][0] + i);

	return sum;
}

