// Improve p11_5.c in chap 5
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define LOOP_MESSAGE "Loop this program?(y/n): "
#define TERMINATE_MESSAGE "Program terminated.\n"
#define TENS 10
#define UNITS 10

// Prototypes(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int main(void){
	bool loop = true;

	while(loop){
		int tens, units;
		char *tens_arr[TENS] = {" ", " ", "twenty", "thirty", "forty", "fifty",\
							"sixty", "seventy", "eight", "ninety"};
		char *ten_to_nineteen[UNITS] = {"ten", "eleven", "twelve", "thirteen", "fourteen",\
								"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
		char *units_arr[UNITS] = {"", "-one", "-two", "-three", "-four", "-five", "-six",\
							"-seven", "-eight", "-nine"};

		printf("Enter a 2-digit number: ");
		scanf("%1d%1d", &tens, &units);
		while (getchar() != '\n');
		printf("You entered the number ");
		if (tens > 1){
			printf("%s%s.\n", tens_arr[tens], units_arr[units]);
		}
		else if (tens == 1) {
			printf("%s.\n", ten_to_nineteen[units]);
		}
		else {
			printf("%s.\n", units ? &units_arr[units][1] : "zero");
		}

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
