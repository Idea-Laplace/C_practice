/************************************************
 * p2_13 Modify reminder.c in section 13.5      *
 * (a) Have the program print an error message  *
 * and ignore a reminder oif the corresponding  *
 * day is negative or larger than 31.           *
 * (b) Allow the user to enter a day, a 24 hour *
 * time, and a reminder.                        *
 * (c) Have the program print a one-year remind-*
 * -er list. Require the user to enter days in  *
 *  the form of month/day                       *
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
#define DAY_INFORM 12
#define LOOP_MESSAGE "Loop this program?(y/n): "
#define TERMINATE_MESSAGE "Program terminated.\n"

// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *teminate_message);
int read_line(char str[], int n);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char reminders[MAX_REMIND][DAY_INFORM + MSG_LEN + 1];
		char day_str[DAY_INFORM + 1], msg_str[MSG_LEN + 1];
		int month, day, hour, minute, i, j, num_remind = 0;
		bool subloop = true;

		while (subloop){
			for (;;){
				if (num_remind == MAX_REMIND){
					printf("----- No space left. ------\n");
					break;
				}

				printf("Enter day, time and reminder: ");
				scanf("%2d/%2d", &month, &day);
				if (month == 0){
					while(getchar() != '\n');
					break;
				}
				if (day < 0 || day > 31 || month < 0 || month > 12){
					printf("Day out of range, ignored.\n");
					continue;
				}

				scanf("%2d :%2d", &hour, &minute);
				if (hour < 0 || hour > 23 || minute < 0 || minute > 59){
					printf("Time expression out of range, ignored.\n");
					continue;
				}

				sprintf(day_str, "%2d/%2d %2.2d:%2.2d", month, day, hour, minute);
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

			if (month)
				while (getchar() != '\n');
			loop_decision(&subloop, "Do you want add more?(y/n): ", "Present reminder erased.\n");
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

int read_line(char str[], int n){
	int ch;
	char *p;
	for (p = str; (ch = getchar()) != '\n' && (p - str) < n; ++p)
		*p = ch;
	*p = '\0';
	return (int) (p - str);
}
