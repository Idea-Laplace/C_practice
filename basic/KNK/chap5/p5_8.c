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
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;
	int table[8];
	table[0] = 480;
	table[1] = 583;
	table[2] = 629;
	table[3] = 767;
	table[4] = 840;
	table[5] = 945;
	table[6] = 1140;
	table[7] = 1305;

	while(loop){
		int reply = 0;
		int index, hour, minute, minute_expr;
		printf("Enter a 24-hour time.(hh:mm): ");
		scanf("%d :%d", &hour, &minute);
		getchar();
		minute_expr = 60 * hour + minute;
		
		if (minute_expr < 0 || minute_expr >= 1440){
			printf("Incorrect time format, try again.\n");
			continue;
		}
		
		if (minute_expr < table[0])
			printf("Closest departure time is 08:00 a.m., arriving at 10:00 a.m.\n");
		else if (minute_expr < table[1])
			printf("Closest departure time is 09:43 a.m., arriving at 11:52 a.m.\n");
		else if (minute_expr < table[2])
			printf("Closest departure time is 11:19 a.m., arriving at 01:31 p.m.\n");
		else if (minute_expr < table[3])
			printf("Closest departure time is 12:47 p.m., arriving at 03:00 p.m.\n");
		else if (minute_expr < table[4])
			printf("Closest departure time is 02:00 p.m., arriving at 04:08 p.m.\n");
		else if (minute_expr < table[5])
			printf("Closest departure time is 03:45 p.m., arriving at 05:55 p.m.\n");
		else if (minute_expr < table[6])
			printf("Closest departure time is 07:00 p.m., arriving at 09:20 p.m.\n");
		else if (minute_expr < table[7])
			printf("Closest departure time is 09:45 p.m., arriving at 11:58 p.m.\n");
		else
			printf("Closest departure time is tomorrow 08:00 a.m., arriving at 10:00 a.m.\n");


		while (reply != 'y' && reply != 'n'){
			printf("\nLoop this program?(y/n) > ");
			reply = getchar();
			getchar();

			switch(reply){
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("\nProgram terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		}
	}
	system("pause");
	return 0;
}
