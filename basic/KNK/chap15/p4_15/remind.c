#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "readline.h"
#include "template.h"

#define MAX_REMIND 50 // Maximum numbers of reminders.
#define MSG_LEN 60 // Max length of reminder message.
#define DATE_TIME 13 // Spaces to store date-time expression.


int main(void) {
	bool loop = true;
	char reminders[MAX_REMIND][DATE_TIME + MSG_LEN + 1] = {0};
	char date_time[DATE_TIME], msg_str[MSG_LEN + 1];
	int month, date, hour, minute;
	int legal_expression;
	int num_remind = 0,  i, j;

	while (loop) {
		if (num_remind >= MAX_REMIND) {
			printf("--No space left.--\n");
			break;
		}

		printf("Enter date and time that you want to add a reminder (mm/dd hh:mm): ");
		legal_expression = scanf("%d /%d %d :%d", &month, &date, &hour, &minute);
		if (legal_expression != 4) {
			printf("Invalid input, ignored.\n");
			printf("=========================================\n");
			while (getchar() != '\n');
			continue;
		}
		sprintf(date_time, "%02d/%02d %02d:%02d ", month, date, hour, minute);
		while (getchar() != '\n');

		printf("Enter reminder: ");
		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++)
			if (strcmp(date_time, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j-1]);

		strcpy(reminders[i], date_time);
		strcat(reminders[i], msg_str);

		num_remind++;

		loop_decision(&loop);
	}

	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}
