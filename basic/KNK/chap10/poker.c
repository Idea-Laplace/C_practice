// Classifies a poker hand

#include <stdio.h>
#include <stdlib.h> // system(), srand(), rand()
#include <stdbool.h> // C99 standard
#include <ctype.h>  // toupper()

// Macro
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

// External variables
int num_in_rank[NUM_RANKS];            // Save 'rank' of 5 cards
int num_in_suit[NUM_SUITS];            // Save 'suit' of 5 cards
bool straight, flush, four, three;     // State variables of 5 cards
int pairs; // can be 0, 1, or 2         // Ditto.

// Prototypes
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/***********************************************************
 * main : Calls read_cards, analyze_hand, and print_result *
 *        repeatedly.                                      *
 ***********************************************************/
int main(void) {
	for(;;) {

		read_cards();
		analyze_hand();
		print_result();


		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch (reply) {
				case 'Y': printf("\n=========================\n"); break;
				case 'N': printf("Program terminated.\n"); goto end;
				default : printf("Type y[Y] or n[N].\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	end:
	system("pause");
	return 0;
}

/***********************************************************
 * read_cards: Reads the cards into the external variables *
 *             num_in_rank and num_in_suit;                *
 *             checks for bad cards and duplicate cards.   *
 ***********************************************************/
void read_cards(void) {
	bool card_exists[NUM_RANKS][NUM_SUITS];     // Check duplicate card, which is invalid.
	char separation_ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_card;                              // Invalid input case.
	int cards_read = 0;                          // Count what number of cards the process has read.

	// Initialize num_in_rank and card_exists
	for (rank = 0; rank <NUM_RANKS; ++rank) {
		num_in_rank[rank] = 0;
		for (suit = 0; suit < NUM_SUITS; ++suit)
			card_exists[rank][suit] = false;
	}

	// Initialize num_in_suit
	for (suit = 0; suit < NUM_SUITS; ++suit)
		num_in_suit[suit] = 0;

	// Reading card part
	while (cards_read < NUM_CARDS) {
		bad_card = false;

		printf("Enter a card: ");

		// Determine rank
		rank_ch = toupper(getchar());
		switch (rank_ch) {
			case '0': printf("Program Terminated.\n"); system("pause"); exit(EXIT_SUCCESS);
			case '2': rank = 0; break;
			case '3': rank = 1; break;
			case '4': rank = 2; break;
			case '5': rank = 3; break;
			case '6': rank = 4; break;
			case '7': rank = 5; break;
			case '8': rank = 6; break;
			case '9': rank = 7; break;
			case 'T': rank = 8; break;
			case 'J': rank = 9; break;
			case 'Q': rank = 10; break;
			case 'K': rank = 11; break;
			case 'A': rank = 12; break;
			default: bad_card = true; break;
		}

		// Determine suit
		suit_ch = toupper(getchar());
		switch (suit_ch) {
			case 'C': suit = 0; break;
			case 'D': suit = 1; break;
			case 'H': suit = 2; break;
			case 'S': suit = 3; break;
			default: bad_card = true; break;
		}

		while((separation_ch = getchar()) != '\n')
			if (separation_ch != ' ') bad_card = true;

		if (bad_card)
			printf("Bad card, ignored.\n");
		else if (card_exists[rank][suit])
			printf("Duplicate card, ignored.\n");
		else {
			++num_in_rank[rank];
			++num_in_suit[suit];
			card_exists[rank][suit] = true;
			++cards_read;
		}
	}
}

/***********************************************************
 * analyze_hand: Determines whether the hand contains a    *
 *               straight, a flush, four-of-a-kind,        *
 *               and/or three-of-kind; determines the      *
 *               number of pairs; stores the results into  *
 *               the external variables straight, flush,   *
 *               four, three, and pairs.                   *
 ***********************************************************/
void analyze_hand(void) {
	int num_consec = 0; // variable for check for straight
	int rank, suit;
	straight = flush = four = three = false;
	pairs = 0;

	// Check for flush
	for (suit = 0; suit < NUM_SUITS; ++suit)
		if (num_in_suit[suit] == NUM_CARDS)
			flush = true;

	// Check for straight
	rank = 0;
	while (num_in_rank[rank] == 0)
		++rank;
	for (; suit < NUM_RANKS && num_in_rank[rank] > 0; ++rank)
		num_consec++;
	if (num_consec == NUM_CARDS) {
		straight = true;
		return;                   // When straight is true, no other cases happen but flush.
	}

	// Check for 4-of-kind, 3-of-kind and pairs.
	for (rank = 0; rank < NUM_RANKS; ++rank) {
		if (num_in_rank[rank] == 4)
			four = true;
		if (num_in_rank[rank] == 3)
			three = true;
		if (num_in_rank[rank] == 2)
			++pairs;
	}
}

/************************************************************
 * print_result: Prints the classification of the hand,     *
 *               based on the values of the external        *
 *               variables straight, flush, four, three,    *
 *               and pairs.                                 *
 ************************************************************/
void print_result(void) {
	if (straight && flush)
		printf("Straight Flush!!!\n");
	else if (four)
		printf("Four of a kind!!\n");
	else if (three && pairs)
		printf("Full house!!\n");
	else if (flush)
		printf("Flush!\n");
	else if (straight)
		printf("Straight!\n");
	else if (three)
		printf("Three of a kind!\n");
	else if (pairs == 2)
		printf("Two pairs.\n");
	else if (pairs == 1)
		printf("Pair.\n");
	else
		printf("High card.\n");
}

