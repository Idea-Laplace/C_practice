#include <stdio.h>
#include <stdlib.h>
#define CHESS 8


int main(void) {
	char chess_board[CHESS][CHESS] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},\
									{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},\
									{' ', '*', ' ', '*', ' ', '*', ' ', '*'},\
									{'*', ' ', '*', ' ', '*', ' ', '*', ' '},\
									{' ', '*', ' ', '*', ' ', '*', ' ', '*'},\
									{'*', ' ', '*', ' ', '*', ' ', '*', ' '},\
									{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},\
									{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
	for (int i = 0; i < CHESS; ++i) {
		for (int j = 0; j < CHESS; ++j)
			printf(" %c ", chess_board[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
