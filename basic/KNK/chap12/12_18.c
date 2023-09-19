/************************************************
 * 12 - 18
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Macro
#define CHESS 8

// External Variable(s)

// Prototype(s)
int evaluate_position(char board[CHESS][CHESS]);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char board[CHESS][CHESS] = {0};
		int count[12] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 8, 8};
		const char set_unit[12] = {'K', 'k', 'Q', 'q', 'R', 'r', 'B', 'b', 'N', 'n', 'P', 'p'};

		srand((unsigned) time(NULL));

		for (char *p = board[0]; p - board[0] < CHESS*CHESS; ++p){
			int unit = rand() % 12;
			if (count[unit]){
				*p = set_unit[unit];
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
int evaluate_position(char board[CHESS][CHESS]){
	int white_value = 0, black_value = 0;

	for (char *p = board[0]; p < board[0] + CHESS*CHESS; ++p){
		if (*p == 0)
			continue;

		switch (*p) {
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
