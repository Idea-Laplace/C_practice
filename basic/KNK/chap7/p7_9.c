#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


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
		int hour, minute, minute_expr;
		char ch1, ch2;
		printf("Enter a 12-hour time.(hh:mm): ");
		scanf("%d :%d %c%c", &hour, &minute, &ch1, &ch2);
		getchar();

		switch (toupper(ch1)) {
			case 'A':
				switch (toupper(ch2)) {
					case 'M': case '\n':
						if (hour == 12) {
							printf("Invalid format, try again.\n"); continue;
						}
						minute_expr = 60 * hour + minute; break;
					default : printf("Invalid format, try again.\n"); continue;
				}
				break;
			case 'P':
				switch (toupper(ch2)) {
					case 'M': case '\n':
						if (hour == 12) {
							minute_expr = 60 * hour + minute; 
							break;
						}
						minute_expr = 60 * hour + 720 + minute; break;
					default : printf("Invalid format, try again.\n"); continue;
				}
				break;
			default : printf("Invalid format, try again.\n"); continue;
		}
		
		if (minute_expr < 0 || minute_expr >= 1440) {
			printf("Incorrect time format, try again.\n");
			continue;
		}
		
		printf("Equivalent 24-hour time: %.2d:%.2d\n", minute_expr / 60, minute_expr % 60);

		char reply;
		do {
			printf("\nLoop this program?(y/n) > ");
			reply = getchar();
			getchar();

			switch(reply){
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("\nProgram terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			} 
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
