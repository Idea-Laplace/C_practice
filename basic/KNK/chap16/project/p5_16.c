/*******************************
 * Departure        Arrival    *
 * 08:00 a.m.       10:00 a.m. *
 * 09:43 a.m.       11:52 a.m. *
 * 11:19 a.m.       01:31 p.m. *
 * 12:47 p.m.       03:31 p.m. *
 * 02:00 p.m.       04:08 p.m. *
 * 03:45 p.m.       05:55 p.m. *
 * 07:00 p.m.       09:20 p.m. *
 * 09:45 p.m.       11:58 p.m. *
 *******************************/

#include <stdio.h>
typedef struct {
	int departure;
	int arrival;
} time_table;

int main(void){
	time_table table[8] = {
							{480, 600}, {583, 712},
							{629, 811}, {767, 931},
							{840, 968}, {945, 1075},
							{1140, 1280}, {1305, 1438}};

	int reply = 0;
	int index, hour, minute, minute_expr;
	printf("Enter a 24-hour time.(hh:mm): ");

	for (;;) {
		int valid_input;
		valid_input = scanf("%d :%d", &hour, &minute);
		while (getchar() != '\n');
		if (valid_input != 2) {
			printf("Invalid input, ignored.\n");
			continue;
		}

		minute_expr = 60 * hour + minute;
		
		if (minute_expr < 0 || minute_expr >= 1440){
			printf("Incorrect time format, try again.\n");
			continue;
		}

		break;
	}
	
	if (minute_expr < table[0].departure)
		printf("Closest departure time is 08:00 a.m., arriving at 10:00 a.m.\n");
	else if (minute_expr < table[1].departure)
		printf("Closest departure time is 09:43 a.m., arriving at 11:52 a.m.\n");
	else if (minute_expr < table[2].departure)
		printf("Closest departure time is 11:19 a.m., arriving at 01:31 p.m.\n");
	else if (minute_expr < table[3].departure)
		printf("Closest departure time is 12:47 p.m., arriving at 03:00 p.m.\n");
	else if (minute_expr < table[4].departure)
		printf("Closest departure time is 02:00 p.m., arriving at 04:08 p.m.\n");
	else if (minute_expr < table[5].departure)
		printf("Closest departure time is 03:45 p.m., arriving at 05:55 p.m.\n");
	else if (minute_expr < table[6].departure)
		printf("Closest departure time is 07:00 p.m., arriving at 09:20 p.m.\n");
	else if (minute_expr < table[7].departure)
		printf("Closest departure time is 09:45 p.m., arriving at 11:58 p.m.\n");
	else
		printf("Closest departure time is tomorrow 08:00 a.m., arriving at tomorrow 10:00 a.m.\n");


	return 0;
}
