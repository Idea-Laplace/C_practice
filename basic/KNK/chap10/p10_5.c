// Classifies a poker hand, without using external array variables.
// Use just one array variable.

#include <stdio.h>
#include <stdlib.h> // system(), srand(), rand()
#include <stdbool.h> // C99 standard
#include <ctype.h>  // toupper()

// Macro
#define NUM_CARDS 5
#define NUM_RANKS 13
#define RANK_INFO 0
#define SUIT_INFO 1
#define INFO 2

// External variables
bool royal, straight, flush, four, three;     // State variables of 5 cards
int pairs; // can be 0, 1, or 2        // Ditto.

// Prototypes
void read_cards(int [NUM_CARDS][2]);
void analyze_hand(int [NUM_CARDS][2]);
void print_result(void);

/***********************************************************
 * main : Calls read_cards, analyze_hand, and print_result *
 *        repeatedly.                                      *
 ***********************************************************/
int main(void) {
	for(;;) {
		int hand[NUM_CARDS][INFO] = {0};   // Save information of 5 cards

		read_cards(hand);
		analyze_hand(hand);
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
void read_cards(int hand[NUM_CARDS][2]) {
	char separation_ch, rank_ch, suit_ch;
	int rank, suit;
	int card, info;
	bool bad_card, duplicate;                   // Invalid input case.
	int cards_read = 0;                         // Count what number of cards the process has read.

	// Initialize hand
	for (card = 0; card < NUM_CARDS; ++card)
		for (info = 0; info < 2; ++info)
			hand[card][info] = 0;

	while (cards_read < NUM_CARDS) {
		bad_card = duplicate = false;

		// Input
		printf("Enter a card: ");
		rank_ch = toupper(getchar());
		switch (rank_ch) {
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
		suit_ch = toupper(getchar());
		switch (suit_ch) {
			case 'S': suit = 4; break;
			case 'D': suit = 3; break;
			case 'H': suit = 2; break;
			case 'C': suit = 1; break;
			default : bad_card = true; break;
		}
		while((separation_ch = getchar()) != '\n')
			if (separation_ch != ' ') bad_card = true;

		// Read card
		for (int i = 0; i < cards_read; ++i)
			if (hand[i][RANK_INFO] == rank && hand[i][SUIT_INFO] == suit) {
				duplicate = true;
				break;
			}

		if (bad_card)
			printf("Bad card, ignored.\n");
		else if (duplicate)
			printf("Duplicate card, ignored.\n");
		else {
			hand[cards_read][RANK_INFO] = rank;
			hand[cards_read][SUIT_INFO] = suit;
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
void analyze_hand(int hand[NUM_CARDS][INFO]) {
	int same;            // Variable for checking four, three, and pairs.
	royal = false;
	flush = straight = true;
	four = three = false;

	pairs = 0;

	// Check for flush
	for (int card = 0; card < NUM_CARDS - 1; ++card)
		if (hand[card][SUIT_INFO] != hand[card + 1][SUIT_INFO]) {
			flush = false;
			break;
		}

	// Sort by rank
	int temp, i;
	int end_idx = NUM_CARDS - 1;
	int max_idx = 0;
	while (end_idx > 0) {
		for (i = 0; i <= end_idx; ++i) {
			if (hand[max_idx][RANK_INFO] < hand[i][RANK_INFO]) {
				max_idx = i;
			}
		}
		temp = hand[end_idx][RANK_INFO];
		hand[end_idx--][RANK_INFO] = hand[max_idx][RANK_INFO];
		hand[max_idx][RANK_INFO] = temp;
		max_idx = 0;
	}

	// Check for straight;
	for (i = 0; i < NUM_CARDS - 1; ++i)
		if (hand[i][RANK_INFO] + 1 != hand[i + 1][RANK_INFO]) {
			if (i == 3 && hand[4][RANK_INFO] == 12)
				break;
			straight = false;
			break;
		}

	if (straight && hand[0][0] == 8)
		royal = true;

	// Check for 4-of-a-kind, 3-of-a-kind, and pair.
	i = 0;
	do {
		same = 1;
		for (;hand[i][RANK_INFO] == hand[i + 1][RANK_INFO]; ++i)
			++same;
		switch (same) {
			case 2: ++pairs; break;
			case 3: three = true; break;
			case 4: four = true; break;
			default: break;
		}
	} while (++i < NUM_CARDS - 1);
}

/************************************************************
 * print_result: Prints the classification of the hand,     *
 *               based on the values of the external        *
 *               variables straight, flush, four, three,    *
 *               and pairs.                                 *
 ************************************************************/
void print_result(void) {
	if (flush && royal)
		printf("Royal straight flush!!!!!!\n");
	else if (straight && flush)
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

