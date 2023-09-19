/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Macro
#define WEEK 7
#define HOUR 24
#define INCREASE 3
#define DECREASE_EVENING 1
#define DECREASE_NIGHT 2
#define LOW_CORRECTION 1

// External Variable(s)

// Prototype(s)
bool search(const int array[], int length_of_array, int key);
int find_largest(int array[], int length_of_array);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Initialize a temperature table =========================================
		int temperature[WEEK][HOUR];
		const char days[][7] = {"Sun", "Mon", "Tue", "Wed", "Thu",\
								"Fri", "Sat"};
		int key_t;
		srand(time(NULL));
		for (int *p = temperature[0]; (p - temperature[0]) < WEEK * HOUR; ++p){
			int hour = (p - temperature[0]) % HOUR;
			if (p == temperature[0])
				*p = rand() % 15 + 10;
			else if (hour < 6 || hour > 18)
				*p = *(p - 1) - (rand() % DECREASE_NIGHT + LOW_CORRECTION);
			else if (hour > 15 && hour <= 18)
				*p = *(p - 1) - (rand() % DECREASE_EVENING + LOW_CORRECTION);
			else
				*p = *(p - 1) + (rand() % INCREASE + LOW_CORRECTION);
		}
		// ========================================================================

		// Print the temperature table ============================================
		printf("    |");
		for (int i = 0; i < 24; ++i)
			printf("%2d  ", i);
		printf("\b\b|\n");
		for (int i = 0; i < 25; ++i)
			printf("----");
		printf("\n");
		for (int *p = temperature[0]; (p - temperature[0]) < WEEK * HOUR; ++p){
			int hour = (p - temperature[0]) % HOUR;
			int day = (p - temperature[0]) / HOUR;
			if (hour == 0){
				printf("%3s |", days[day]);
			}
			printf("%2d, ", *p);
			if (hour == HOUR - 1){
				printf("\b\b|\n");
			}
		}
		for (int i = 0; i < 25; ++i)
			printf("----");
		printf("\n");
		// =======================================================================

		// Search ================================================================
		char repeat;
		do {
			printf("Enter a temperature to be searched: ");
			scanf("%d", &key_t);
			while (getchar() != '\n');

			bool result;
			result = search(temperature[0], WEEK * HOUR, key_t);
			printf("The temperature %d is %s in the given table.\n", key_t, result ? "\b" : "not");
			printf("If you want to go next step, press 'e': ");
			repeat = toupper(getchar());
			while (getchar() != '\n');
		} while (repeat != 'E');
		// =======================================================================

		// Print the highest temperature of each day =============================
		for (int i = 0; i < WEEK; ++i){
			printf("%s: %d\n", days[i], find_largest(temperature[i], HOUR));
		}
		// =======================================================================


		// Loop decision =========================================================
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
		// ========================================================================
	}
	system("pause");
	return 0;
}

// Function(s)
bool search(const int array[], int length_of_array, int key){
	bool match_key = false;
	for (int i = 0; i < length_of_array; ++i){
		if (key == *(array + i)){
			match_key = true;
		}
	}
	return match_key;
}
int find_largest(int array[], int length_of_array){
	int largest = array[0];
	for (int *p = array; p < array + length_of_array; ++p){
		if (largest < *p)
			largest = *p;
	}
	return largest;
}

