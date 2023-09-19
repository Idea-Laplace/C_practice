/************************************************
 * p2_13 Modify reminder.c in section 13.5      *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define MAX_REMIND 50
#define MSG_LEN 60
#define LOOP_MESSAGE "Loop this program?(y/n): "

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *message);
int read_line(char str[], int n);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char reminders[MAX_REMIND][3 + MSG_LEN];
		char day_str[3], msg_str[MSG_LEN + 1];
		int day, i, j, num_remind = 0;
		bool subloop = true;

		while (subloop){
			for (;;){
				if (num_remind == MAX_REMIND){
					printf("----- No space left. ------\n");
					break;
				}

				printf("Enter day and reminder: ");
				scanf("%2d", &day);
				if (day == 0)
					break;
				sprintf(day_str, "%2d", day);
				read_line(msg_str, MSG_LEN);

				// Determine the position of new-reminder message.
				for (i = 0; i < num_remind; ++i)
					if (strcmp(day_str, reminders[i]) < 0)
						break;
				// Put existing messages aside by 1 space
				for (j = num_remind; j > i; --j)
					strcpy(reminders[j], reminders[j-1]);

				strcpy(reminders[i], day_str);
				strcat(reminders[i], msg_str);

				num_remind++;
			}

			printf("\nDay Reminder\n");
			for (i = 0; i < num_remind; ++i)
				printf(" %s\n", reminders[i]);

			while (getchar() != '\n');
			loop_decision(&subloop, "Do you want add more?(y/n): ");
		}
		while (getchar() != '\n');

		// Loop decision
		loop_decision(&loop, LOOP_MESSAGE);
	}
	system("pause");
	return 0;
}

// Function(s)
void loop_decision(bool *loop, char *message){
	int reply;
	do {
		printf("%s", message);
		reply = toupper(getchar());
		while (getchar() != '\n');
		switch (reply){
			case 'Y': printf("\n===================================\n"); break;
			case 'N': printf("\n===================================\n");
					  printf("Program terminated.\n");
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
