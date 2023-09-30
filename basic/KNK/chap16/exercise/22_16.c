#include <stdio.h>

int main(void) {
	typedef enum {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN} chess_pieces;
	int piece_value[] = {200, 9, 5, 3, 3, 1};
	int piece_value_subscript[] = {
				[KING] = 200,
				[QUEEN] = 9,
				[ROOK] = 5,
				[BISHOP] = 3,
				[KNIGHT] = 3,
				[PAWN] = 1
	};

	for (int i = 0; i < 6; i++) {
		printf("%d, ", piece_value[i]);
	}
	printf("\b\b\n");

	for (int i = 0; i < 6; i++) {
		printf("%d, ", piece_value_subscript[i]);
	}
	printf("\b\b\n");
	return 0;
}
