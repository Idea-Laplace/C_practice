#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int evaluate_position(char board[8][8]);

int main(void) {
	for (;;) {
		char board[8][8] = {0};
		int count[12] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 8, 8};
		const char set_unit[12] = {'K', 'k', 'Q', 'q', 'R', 'r', 'B', 'b', 'N', 'n', 'P', 'p'};

		srand((unsigned) time(NULL));

		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j) {
				int unit = rand() % 12;
				if (count[unit]) {
					board[i][j] = set_unit[unit];
					--count[unit];
				}
			}

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) 
				printf("%c ", board[i][j] ? board[i][j] : '*');
			printf("\n");
		}

		printf("Difference(w - b): %d\n", evaluate_position(board));
		if (evaluate_position(board) > 0)
			printf("Win: white\n");
		else if (evaluate_position(board) < 0)
			printf("Win: black\n");
		else
			printf("Draw\n");

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n==============================\n"); break;
				case 'n': printf("Program terminated.\n"); goto end;
				default : printf("Enter y or n.\n"); break;
			}
		} while (reply != 'y');
	}
	end:
	system("pause");
	return 0;
}


int evaluate_position(char board[8][8]) {
	int white_value = 0, black_value = 0;

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == 0)
				continue;

			switch (board[i][j]) {
				case 'K': case 'k': break;

				case 'Q': white_value += 9; break;
				case 'R': white_value += 5; break;
				case 'B': white_value += 3; break;
				case 'N': white_value += 3; break;
				case 'P': white_value += 1; break;

				case 'q': black_value += 9; break;
				case 'r': black_value += 5; break;
				case 'b': black_value += 3; break;
				case 'n': black_value += 3; break;
				case 'p': black_value += 1; break;

				default : printf("Error: Invalid character included.\n"); return -1;
			}
		}
	return white_value - black_value;
}
