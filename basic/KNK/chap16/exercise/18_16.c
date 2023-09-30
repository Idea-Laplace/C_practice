#include <stdio.h>

typedef struct {
	enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
	enum {BLACK, WHITE} Color;
} chess_board_square;

int main(void) {
	chess_board_square chess_board[8][8] = \
				{{{ROOK}, {KNIGHT}, {BISHOP}, {QUEEN}, {KING}, {BISHOP}, {KNIGHT}, {ROOK}},
				 {{PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}},
				 {{EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}},
				 {{EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}},
				 {{EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}},
				 {{EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}, {EMPTY}},
				 {{PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}},
				 {{ROOK}, {KNIGHT}, {BISHOP}, {QUEEN}, {KING}, {BISHOP}, {KNIGHT}, {ROOK}}};

	chess_board_square *p = *chess_board;
	for (p = *chess_board; (p - *chess_board) < 64; ++p) {
		if ((p - *chess_board) % 2)
			(*p).Color = BLACK;
		else
			(*p).Color = WHITE;
	}

	for (int i = 0; i < 64; i++) {
		printf("(%d, %d): Piece-%d, Color-%d\n", i / 8, i % 8, chess_board[i/8][i%8].Piece, chess_board[i/8][i%8].Color);
	}
	
	return 0;
}
	

