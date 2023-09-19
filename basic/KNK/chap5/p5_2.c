#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int hour, minute, reply;
	bool loop = true;

	while(loop){
		reply = 0;
		printf("Enter a 24-hour time(In a form hh:mm): ");
		scanf("%d :%d", &hour, &minute);
		getchar();

		if (hour > 23 || hour < 0 || minute > 59 || minute < 0)
			printf("Input proper time form.\n");
		else if (hour < 12)
			printf("Equivalent 12-hour time: %2.2d:%2.2d AM.\n", hour, minute);
		else if (hour > 12)
			printf("Equivalent 12-hour time: %2.2d:%2.2d PM.\n", hour % 12, minute);
		else
			printf("Equivalent 12-hour time: %2.2d:%2.2d PM.\n", hour, minute);
			
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
