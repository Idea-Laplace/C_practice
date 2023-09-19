#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
	int win = 0, lose = 0;
	for (;;) {

		if (play_game())
			++win;
		else
			++lose;
		
		// Repeat decision
		char reply;
		do {
			printf("Play again?(y/n): ");
			reply = toupper(getchar());
			getchar();

			switch (reply) {
				case 'Y': printf("\n==============================\n"); break;
				case 'N': printf("Program terminated.\n"); goto end;
				default : printf("Enter y[Y] or n[N].\n"); break;
			}
		} while (reply != 'Y');
	}
	end:
	printf("Wins: %d\t Losses: %d\n", win, lose);
	system("pause");
	return 0;
}


int roll_dice(void) {
	int num1, num2;
	num1 = rand() % 6 + 1;
	num2 = rand() % 6 + 1;

	return num1 + num2;
}

bool play_game(void) {
	bool opening = true;
	int point;

	srand((unsigned) time(NULL)); // When srand() is in loop, loop is too fast to randomize roll_dice
	while (true) {
		int sum = roll_dice();

		printf("You rolled: %d\n", sum);

		// First roll
		if (opening) {
			if (sum == 7 || sum == 11) {
				printf("You win!\n");
				return true;
			}
			else if (sum == 2 || sum == 3 || sum == 12) {
				printf("You lose.\n");
				return false;
			}
			else {
				printf("Your point is %d\n", sum);
				point = sum;
				opening = false;
				continue;
			}
		}
		// Subsequent roll
		if (!opening) {
			if (sum == point) {
				printf("You win!\n");
				return true;
			}
			else if (sum == 7) {
				printf("You lose.\n");
				return false;
			}
			else
				continue;
		}
	}
}







