/************************************************
 * KNK 2nd edition chap12 problem 1             *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Macro
#define LENGTH(array) ((int) sizeof(array) / sizeof(array[0]))

// External Variable(s)

// Prototype(s)
// Main
int main(void){ 
	bool loop = true;
	while (loop){
	// Main I/O process
		srand(time(NULL));
		int length = (rand() % 5) + 8;
		int transition = rand() % 3 + 1;
		int index_restriction_p;
		int index_restriction_q;
		int pq_restriction;
		int arr[length], *p, *q;

		// Randomize an array
		for (p = arr; p < arr + LENGTH(arr); ++p)
			*p = rand() % 100;

		printf("A given array is: ");
		printf("{");
		for (int i = 0; i < LENGTH(arr); ++i){
			printf("%d, ", arr[i]);
		}
		printf("\b\b}\n");

		// Randomize pointers p and q
		index_restriction_p = rand() % (LENGTH(arr) - transition);
		p = arr + index_restriction_p;
		pq_restriction = index_restriction_p > transition ? index_restriction_p : transition;
		index_restriction_q = rand() % (LENGTH(arr) - pq_restriction) + pq_restriction;
		q = arr + index_restriction_q;
		printf("p = &arr[%d], q = &arr[%d] are given.\n", index_restriction_p, index_restriction_q);

		// Problems
		int correct = 0;
		int answer;
		printf("========================================\n");
		printf("What is the value of *(p+%d)? : ", transition);
		scanf("%d", &answer);
		while (getchar() != '\n');
		if (answer == *(p + transition)){
			printf("Correct.\n");
			++correct;
		}
		else {
			printf("Incorrect, the answer is %d.\n", *(p+transition));
		}
		printf("========================================\n");
		printf("What is the value of *(q-%d)? : ", transition);
		scanf("%d", &answer);
		while (getchar() != '\n');
		if (answer == *(q - transition)){
			printf("Correct.\n");
			++correct;
		}
		else {
			printf("Incorrect, the answer is %d.\n", *(q-transition));
		}
		printf("========================================\n");
		printf("What is the value of q-p? : ");
		scanf("%d", &answer);
		while (getchar() != '\n');
		if (answer == (int) (q - p)){
			printf("Correct.\n");
			++correct;
		}
		else {
			printf("Incorrect, the answer is %d.\n", (int) (q-p));
		}
		printf("========================================\n");
		printf("Is the condition p < q true or false?[t = 1/f = 0] : ");
		scanf("%d", &answer);
		while (getchar() != '\n');
		if (answer == (int) (p < q)){
			printf("Correct.\n");
			++correct;
		}
		else {
			printf("Incorrect, the answer is %s.\n", p < q ? "true" : "false");
		}
		printf("========================================\n");
		printf("Is the condition *p < *q true or false?[t = 1/f = 0] : ");
		scanf("%d", &answer);
		while (getchar() != '\n');
		if (answer == (int) (*p < *q)){
			printf("Correct.\n");
			++correct;
		}
		else {
			printf("Incorrect, the answer is %s.\n", *p < *q ? "true" : "false");
		}

		printf("Your score is %d/5.\n", correct);


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
