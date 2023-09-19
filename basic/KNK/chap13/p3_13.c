/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Macro
#define LOOP_MESSAGE "Loop this program?(y/n): "
#define TERMINATE_MESSAGE "Program terminated.\n"
#define NUM_SUITS 4
#define NUM_RANKS 13
// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);

// Main
int main(void){
	bool loop = true;
	bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
	int num_cards, rank, suit;
	const char *rank_code[NUM_RANKS] = {"Two", "Three", "Four", "Five", "Six", "Seven",\
									"Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
	const char *suit_code[NUM_SUITS] = {"clubs", "hearts", "diamonds", "spades"};
	while (loop){
		// Main I/O
		srand((unsigned) time(NULL));
		printf("Enter number of cards in hand: ");
		scanf("%d", &num_cards);
		while (getchar() != '\n');
		printf("Your hand:\n");
		while (num_cards > 0){
			suit = rand() % NUM_SUITS;
			rank = rand() % NUM_RANKS;
			if (!in_hand[suit][rank]){
				in_hand[suit][rank] = true;
				--num_cards;
				printf("%s of %s\n", rank_code[rank], suit_code[suit]);
			}
		}
		putchar('\n');

		// Loop decision
		loop_decision(&loop, LOOP_MESSAGE, TERMINATE_MESSAGE);
	}
	system("pause");
	return 0;
}

// Function(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message){
	int reply;
	do {
		printf("%s", loop_message);
		reply = toupper(getchar());
		while (getchar() != '\n');
		switch (reply){
			case 'Y': printf("\n===================================\n"); break;
			case 'N': printf("\n===================================\n");
					  printf("%s", terminate_message);
					  *loop = false;
					  break;
			default : printf("Type y[Y] or n[N] on the first input.\n"); break;
		}
	} while (reply != 'Y' && reply != 'N');
}

int read_line(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}
