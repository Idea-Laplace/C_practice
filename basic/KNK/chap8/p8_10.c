/*******************************
 * Departure        Arrival    *
 * 08:00 a.m.       10:16 a.m. *
 * 09:43 a.m.       11:52 a.m. *
 * 11:19 a.m.       01:31 p.m. *
 * 12:47 p.m.       03:00 p.m. *
 * 02:00 p.m.       04:08 p.m. *
 * 03:45 p.m.       05:55 p.m. *
 * 07:00 p.m.       09:20 p.m. *
 * 09:45 p.m.       11:58 p.m. *
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CATALOG 8
#define DEPARTURE_MINUTE departure[i] % 60
#define DEPARTURE_AM (departure[i] / 60) % 12
#define DEPARTURE_PM (departure[i] / 60) % 12 ? (departure[i] / 60) % 12 : 12
#define ARRIVAL_MINUTE arrival[i] % 60
#define ARRIVAL_AM (arrival[i] / 60) % 12
#define ARRIVAL_PM (arrival[i] / 60) % 12 ? (arrival[i] / 60) % 12 : 12

int main(void){
	bool loop = true;
	const int departure[CATALOG] = {480, 583, 629, 767, 840, 945, 1140, 1305};
	const int arrival[CATALOG] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

	while(loop){
		int hour, minute, minute_expr;
		int i;
		printf("Enter a 24-hour time.(hh:mm): ");
		scanf("%d :%d", &hour, &minute);
		getchar();
		minute_expr = 60 * hour + minute;
		
		if (minute_expr < 0 || minute_expr >= 1440){
			printf("Incorrect time format, try again.\n");
			continue;
		}
		
		for (i = 0; minute_expr >= departure[i]; ++i); // Null body

		if ((departure[i] / 60) < 12)
			printf("Closest departure time is %.2d:%.2d a.m., ", DEPARTURE_AM, DEPARTURE_MINUTE);
		else
			printf("Closest departure time is %.2d:%.2d p.m., ", DEPARTURE_PM, DEPARTURE_MINUTE);

		if ((arrival[i] / 60) < 12)
			printf("Arriving at %.2d:%.2d a.m.\n", ARRIVAL_AM, ARRIVAL_MINUTE);
		else
			printf("Arriving at %.2d:%.2d p.m.\n", ARRIVAL_PM, ARRIVAL_MINUTE);



		char reply = 0;
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
