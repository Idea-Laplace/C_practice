/* p8_9.c is a program that generates a random walk. */

#include <stdio.h>
#include <stdlib.h> // system(), srand(), rand()
#include <stdbool.h> // type bool
#include <time.h> // time()

// For initializing a map design.
#define ROW_SIZE 10
#define COLUMN_SIZE 10
#define ROW position[0]
#define COLUMN position[1]

// Direction
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Exception
#define UP_EXCEPTION (ROW - 1 < 0 || map[ROW - 1][COLUMN])
#define DOWN_EXCEPTION (ROW + 1 > ROW_SIZE - 1 || map[ROW + 1][COLUMN])
#define LEFT_EXCEPTION (COLUMN - 1 < 0 || map[ROW][COLUMN - 1])
#define RIGHT_EXCEPTION (COLUMN + 1 > COLUMN_SIZE - 1 || map[ROW][COLUMN + 1])


int main (void) {
	bool loop = true;

	while (loop) {

		// Initialization
		char map[ROW_SIZE][COLUMN_SIZE], ch = 'A';
		int position[2] = {0, 0};
		for (int i = 0; i < ROW_SIZE; ++i)
			for (int j = 0; j < COLUMN_SIZE; ++j)
				map[i][j] = 0;

		// Random seed
		srand((unsigned) time(NULL));

		// Random walk process
		map[ROW][COLUMN] = ch;  // 'A' is stored in ch at this point.

		while (ch < 'Z') {
			// Handling exceptions & movements
			if (UP_EXCEPTION && DOWN_EXCEPTION && LEFT_EXCEPTION && RIGHT_EXCEPTION)
				break;

			switch (rand() % 4) {
				case UP:
					if (!UP_EXCEPTION)
						map[--ROW][COLUMN] = ++ch;
					break;
				case DOWN:
					if (!DOWN_EXCEPTION)
						map[++ROW][COLUMN] = ++ch;
					break;
				case LEFT:
					if (!LEFT_EXCEPTION)
						map[ROW][--COLUMN] = ++ch;
					break;
				case RIGHT:
					if (!RIGHT_EXCEPTION)
						map[ROW][++COLUMN] = ++ch;
					break;
				default : break;
			}
		}

		// Output
		for (int i = 0; i < ROW_SIZE; ++i) {
			for (int j = 0; j < COLUMN_SIZE; ++j)
				printf(" %c", map[i][j] ? map[i][j] : '*');
			printf("\n");
		}

		// Loop decision
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
