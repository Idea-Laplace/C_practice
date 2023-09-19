#include <stdio.h>
#include <stdlib.h>
#define CHESS 8


int main(void) {
	char chess_board[CHESS][CHESS];
	for (int i = 0; i < CHESS; ++i) {
		for (int j = 0; j < CHESS; ++j) {
			if ((i + j) % 2)
				chess_board[i][j] = 'R';
			else
				chess_board[i][j] = 'B';
		}
	}

	for (int i = 0; i < CHESS; ++i) {
		for (int j = 0; j < CHESS; ++j)
			printf(" %c ", chess_board[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
