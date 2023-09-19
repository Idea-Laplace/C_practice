#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 99                                               // When VLA is not supported.
#define ROW_STEP (row - 1 >= 0 ? row - 1 : odd - 1)          // Row cycle
#define COLUMN_STEP (column + 1 < odd ? column + 1 : 0)      // Column cycle
#define SPACE_CHECK magic_square[ROW_STEP][COLUMN_STEP] == 0 // Determine whether the up-right position is empty.


int main (void) {
	bool loop = true;

	while (loop) {
		int odd, row, column;

		// Input ************************************************************

		printf("This program creates a magic square of a specified size.\n");
		printf("This size must be an odd number between 1 and 99.\n");
		printf("Enter size of magic square: ");
		scanf("%d", &odd);
		getchar(); // Flush '\n'

		if (odd % 2 == 0) {
			printf("\nEnter an \'odd\' number btw 1 and 99\n");
			printf("==================================\n");
			continue;
		}


		// Magic Square Processing ******************************************

		int magic_square[MAX][MAX] = {0};
		magic_square[row = 0][column = odd / 2] = 1;

		for (int i = 2; i <= odd * odd; ++i) 
			if (SPACE_CHECK)
				magic_square[row = ROW_STEP][column = COLUMN_STEP] = i;
			else
				magic_square[++row][column] = i;


		// Output ***********************************************************

		for (int i = 0; i < odd; ++i) {
			for (int j = 0; j < odd; ++j)
				printf("%5d", magic_square[i][j]);
			printf("\n");
		}


		// Loop decision ****************************************************

		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
