#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()

// Macro
#define LENGTH 8

// Global
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
const int table_departure[8] = {480, 583, 629, 767, 840, 945, 1140, 1305};
const int table_arrival[8] = {600, 712, 811, 931, 968, 1075, 1280, 1438};

// Prototype(s)
void find_closest_flight(int desired_time, int *departure,\
						int *arrival);

// Main
int main(void){
	bool loop = true;
	while(loop){
		int desired_time, departure, arrival;
		printf("Enter a value of time in the form of minutes from midnight: ");
		scanf("%d", &desired_time);
		while(getchar() != '\n');

		find_closest_flight(desired_time, &departure, &arrival);
		printf("Departure: %d, Arrival: %d\n", departure, arrival);
		// Loop decision
		char reply;
		do{
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch(reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first character.\n"); break;
			}
		}while(reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}


// Function(s)
void find_closest_flight(int desired_time, int *departure,\
						int *arrival){
	for (int i = 0; i < LENGTH; ++i){
		bool between = desired_time <= table_departure[i] && desired_time <= table_departure[i + 1];
		if (between){
			*departure = table_departure[i];
			*arrival = table_arrival[i];
			break;
		}
	}
}

