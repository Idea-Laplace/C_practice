#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIGIT 10
#define LIGHT 7

void light(bool a[]);
int main(void) {
	bool segments[DIGIT][LIGHT] = {{1, 1, 1, 1, 1, 1, 0},\
								{0, 1, 1, 0, 0, 0, 0},\
								{1, 1, 0, 1, 1, 0, 1},\
								{1, 1, 1, 1, 0, 0, 1},\
								{0, 1, 1, 0, 0, 1, 1},\
								{1, 0, 1, 1, 0, 1, 1},\
								{1, 0, 1, 1, 1, 1, 1},\
								{1, 1, 1, 0, 0, 0, 0},\
								{1, 1, 1, 1, 1, 1, 1},\
								{1, 1, 1, 1, 0, 1, 1}};
	bool loop = true;
	while (loop) {
		int digit;
		char reply;

		printf("Enter a digit: ");
		scanf("%1d", &digit);
		getchar();
		light(segments[digit]);
		
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=======================================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}

	system("pause");
	return 0;
}

void light(bool a[]) {
	if (a[0])
		printf("\t ***** \n");
	else
		printf("\t       \n");
	if (a[5] && a[1]) {
		printf("\t*     *\n");
		printf("\t*     *\n");
		printf("\t*     *\n");
	}
	else if (a[5]) {
		printf("\t*      \n");
		printf("\t*      \n");
		printf("\t*      \n");
	}
	else {
		printf("\t      *\n");
		printf("\t      *\n");
		printf("\t      *\n");
	}
	if (a[6])
		printf("\t ***** \n");
	else
		printf("\t       \n");
	if (a[4] && a[2]) {
		printf("\t*     *\n");
		printf("\t*     *\n");
		printf("\t*     *\n");
	}
	else if (a[4]) {
		printf("\t*      \n");
		printf("\t*      \n");
		printf("\t*      \n");
	}
	else {
		printf("\t      *\n");
		printf("\t      *\n");
		printf("\t      *\n");
	}
	if (a[3])
		printf("\t ***** \n");
	else
		printf("\t       \n");
}
