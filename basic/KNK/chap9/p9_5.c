#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 99                                               // When VLA is not supported.
#define ROW_STEP (row - 1 >= 0 ? row - 1 : odd - 1)          // Row cycle
#define COLUMN_STEP (column + 1 < odd ? column + 1 : 0)      // Column cycle
#define SPACE_CHECK magic_square[ROW_STEP][COLUMN_STEP] == 0 // Determine whether the up-right position is empty.



void create_magic_square(int odd, int magic_square[MAX][MAX]);
void print_magic_square(int odd, int magic_square[MAX][MAX]);

int main (void) {
	bool loop = true;

	while (loop) {
		int odd;
		int magic_square[MAX][MAX] = {0};

		// Input ************************************************************

		printf("This program creates a magic square of a specified size.\n");
		printf("This size must be an odd number between 1 and 99.\n");
		printf("Enter size of magic square: ");
		scanf("%d", &odd);
		getchar(); // Flush '\n'
		
		create_magic_square(odd, magic_square);
		print_magic_square(odd, magic_square);


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


void create_magic_square(int odd, int magic_square[MAX][MAX]) {
	int row = 0, column = 0;

	// Exception
	if (odd < 1 || odd > 99) {
		printf("Caution: Enter an \'odd\' number btw 1 and 99.\n");
		odd = 1;
	}
	if (odd % 2 == 0) {
		printf("Caution: Enter an \'odd\' number btw 1 and 99.\n");
		odd += 1;
	}

	// Magic Square Processing ******************************************

	magic_square[row = 0][column = odd / 2] = 1;

	for (int i = 2; i <= odd * odd; ++i) 
		if (SPACE_CHECK)
			magic_square[row = ROW_STEP][column = COLUMN_STEP] = i;
		else
			magic_square[++row][column] = i;
}


void print_magic_square(int odd, int magic_square[MAX][MAX]) {
	for (int i = 0; i < odd; ++i) {
		for (int j = 0; j < odd; ++j)
			printf("%5d", magic_square[i][j]);
		printf("\n");
	}
}
