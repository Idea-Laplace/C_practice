#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()
#define LENGTH(array) ((int) sizeof(array) / sizeof(array[0]))


// Prototype(s)
void avg_sum(int a[], int n, int *avg, int *sum);


// Main
int main(void){
	bool loop = true;
	while(loop){
		int length, sum, avg;

		printf("Enter a length of an array: ");
		scanf("%d", &length);
		getchar();    // Truncate '\n'
		int array[length];

		for(int i = 0; i < length; ++i){
			printf("Insert an interger on array index %d: ", i);
			scanf("%d", &array[i]);
			getchar();    // Truncate '\n'
		}

		avg_sum(array, LENGTH(array), &avg, &sum);
		printf("Sum: %d,\tAverage: %d\n", sum, avg);
		char reply;
		do{
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch(reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first character.\n"); break;
			}
		}while(reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}


void avg_sum(int a[], int n, int *avg, int *sum){
	*sum = 0;
	for(int i = 0; i < n; ++i)
		*sum += a[i];
	*avg = *sum / n;
}
