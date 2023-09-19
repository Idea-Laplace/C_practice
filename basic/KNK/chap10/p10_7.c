/**************************************
 * INPUT  : 0169                      *
 * OUTPUT :                           *
 *  *****    *****          *****     *
 * *     *  *           *  *     *    *
 * *     *  *           *  *     *    *
 *           *****          *****     *
 * *     *  *     *     *        *    *
 * *     *  *     *     *        *    *
 *  *****    *****          *****     *
 **************************************/
#include <stdio.h>
#include <stdlib.h>  // system()
#include <stdbool.h> // C99 standard
#include <ctype.h>   // toupper()

// Macro ***********************************************************************

// for digits array
#define MAX_INPUT 90          // Numbers after 10th digit will be ignored.
#define LIGHT_ROWS 7          // 9-story-characters needs to represent digital number.

// for segments array
#define DIGIT 10             // from 0 to 9
#define LIGHT 5              // Digital number expression
#define BOTH 4
#define RIGHT 3
#define LEFT 2
#define EXIST 1
#define NONE 0

// *****************************************************************************


// External variables
const int segments[DIGIT][LIGHT] = {{EXIST, BOTH, NONE, BOTH, EXIST},\
									{NONE, RIGHT, NONE, RIGHT, NONE},\
									{EXIST, RIGHT, EXIST, LEFT, EXIST},\
									{EXIST, RIGHT, EXIST, RIGHT, EXIST},\
									{NONE, BOTH, EXIST, RIGHT, NONE},\
									{EXIST, LEFT, EXIST, RIGHT, EXIST},\
									{EXIST, LEFT, EXIST, BOTH, EXIST},\
									{EXIST, BOTH, NONE, RIGHT, NONE},\
									{EXIST, BOTH, EXIST, BOTH, EXIST},\
									{EXIST, BOTH, EXIST, RIGHT, EXIST}};
char digits[LIGHT_ROWS][MAX_INPUT];


// Prototypes
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

// Main
int main(void) {
	for(;;) {
		int length = 0;
		char number;
		char num_list[10] = {0};

		// Input
		clear_digits_array();
		printf("Enter numbers: ");
		while ((number = getchar()) != '\n') {
			if (length > 9)
				continue;
			if (number >= '0' && number <= '9')
				num_list[length++] = number;
		}

		// Process
		for (int i = 0; i  <= length; ++i) 
			process_digit(num_list[i] - '0', i);

		// Output
		print_digits_array();

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

/*************************************************
 *  clear_digits_array: Initialize array digit   *
 *                      by blank ' ';            *
 *************************************************/
void clear_digits_array(void) {
	for (int i = 0; i < LIGHT_ROWS; ++i)
		for (int j = 0; j < MAX_INPUT; ++j)
			digits[i][j] = ' ';
}

/*****************************************************
 *  process_digit: Store literals by numberwise      *
 *                 and positionwise in array digit;  *
 *****************************************************/
void process_digit(int digit, int position) {
	int row = 0;
	for (int i = 0; i < LIGHT; ++i)
		switch (segments[digit][i]) {
			case EXIST:
				for (int j = 0; j < 9; ++j)
					if (j > 2 && j < 8)
						digits[row][9 * position + j] = '*';
				row++;
				break;
			case BOTH:
				for (int j = 0; j < 9; ++j)
					if (j == 2 || j == 8) {
						digits[row][9 * position + j] = '*';
						digits[row + 1][9 * position + j] = '*';
					}
				row += 2;
				break;
			case RIGHT:
				for (int j = 0; j < 9; ++j)
					if (j == 8) {
						digits[row][9 * position + j] = '*';
						digits[row + 1][9 * position + j] = '*';
					}
				row += 2;
				break;
			case LEFT:
				for (int j = 0; j < 9; ++j)
					if (j == 2) {
						digits[row][9 * position + j] = '*';
						digits[row + 1][9 * position + j] = '*';
					}
				row += 2;
				break;
			case NONE: 
				if (digit == 1)
					digits[row][9 * position + 8] = (row != 3 ? '*' : ' ');
				if (digit == 4) {
					digits[row][9 * position + 8] = (row != 3 ? '*' : ' ');
					digits[row][9 * position + 2] = (row == 0 ? '*' : ' ');
				}
				if (digit == 7) 
					digits[row][9 * position + 8] = (row == 6 ? '*' : ' ');
				row++;
				break;
			default: break;
		}
}

void print_digits_array(void) {
	int max;
	for (int i = 0; i < LIGHT_ROWS; ++i)
		for (int j = 0; j < MAX_INPUT; ++j)
			if (digits[i][j] == '*' && max < j)
				max = j;
	printf("\n");
	for (int i = 0; i < LIGHT_ROWS; ++i) {
		for (int j = 0; j <= max; ++j)
			printf("%c", digits[i][j]);
		printf("\n");
	}
	printf("\n");
}
