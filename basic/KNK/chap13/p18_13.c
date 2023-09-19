/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Macro
#define LOOP_MESSAGE "Loop this program?(y/n): "
#define TERMINATE_MESSAGE "Program terminated.\n"
#define LENGTH 100
// External Variable(s)

// Prototype(s)
void loop_decision(bool *loop, char *loop_message, char *terminate_message);
int read_line(char str[], int n);
void convert_date(char *date);

// Main
int main(void){
	bool loop = true;
	while (loop){
		// Main I/O
		char date[LENGTH + 1] = {'\0'};
		printf("Enter a date (mm/dd/yyyy): ");
		read_line(date, LENGTH);
		convert_date(date);

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

void convert_date(char *date) {
	const char *month[12] = {"January", "Feburary", "March", "April", "May",\
						"June", "July", "August", "September", "October",\
						"November", "December"};
	char examine[10 + 1] = {'\0'};
	int i = 0;
	char *num_start, *num_end;
	int count_separator = 0;
	// Examine whether the input is valid ========================
	while (*date && i < 10) {
		if (isspace(*date)) {
			++date;
		}
		else if (isdigit(*date) || *date == '/') {
			examine[i++] = *date++;
		}
		else {
			printf("Invalid input, process terminated.\n");
			return;
		}
	}
	num_start = examine;
	while (*num_start) {
		num_end = num_start;
		if (!isdigit(*num_start)) {
			printf("Invalid input, process terminated.\n");
			return;
		}
		while (*num_end && *num_end != '/') {
			++num_end;
		}
		count_separator++;
		if (count_separator > 2 && *num_end) {
			printf("Invalid input, process terminated.\n");
			return;
		}
		if (count_separator > 2)
			num_start = num_end;
		else
			num_start = num_end + 1;
	}
	// ==========================================================

	// Core process =============================================
	char month_day_year[3][5] = {'\0'};
	const int size_of_month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char *trace = examine;
	int index = 0;
	while (*trace) {
		char *position = trace;
		while (*position != '/' && *position)
			++position;
		*position = '\0';
		switch (index) {
			case 0:
				if (atoi(trace) < 1 || atoi(trace) > 12) {
					printf("Month out of range, process terminated.\n");
					return;
				}
				strcpy(month_day_year[index++], trace);
				trace = position + 1;
				break;
			case 1:
				int temp = atoi(trace);
				if (temp < 1 || temp > size_of_month[atoi(*month_day_year)]) {
					printf("Date out of range, process terminated.\n");
					return;
				}
				strcpy(month_day_year[index++], trace);
				trace = position + 1;
				break;
			case 2:
				if (atoi(trace) < 1 || atoi(trace) > 9999) {
					printf("Year out of range, process terminated.\n");
					return;
				}
				if (atoi(trace) % 4 || (!(atoi(trace) % 100) && (atoi(trace) % 400)))
					if (atoi(month_day_year[1]) == 29) {
						printf("Date out of range, process terminated(leap year issue).\n");
						return;
					}
				strcpy(month_day_year[index++], trace);
				trace = position;
				break;
			case 3:
				break;
			default:
				printf("Unknown error rised, prpcess terminated.\n");
				return;
		}

	}
	printf("You entered the date %s %s, %s\n", month[atoi(month_day_year[0]) - 1],\
			month_day_year[1], month_day_year[2]);
}





