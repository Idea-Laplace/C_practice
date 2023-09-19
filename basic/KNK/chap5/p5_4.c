/*************************************
 * Speed (knots)         Description *
 * Less than 1           calm        *
 * 1 ~ 3                 Light air   *
 * 4 ~ 27                Breeze      *
 * 28 ~ 47               Gale        *
 * 48 ~ 63               storm       *
 * Above 63              Hurricane   *
 *************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;
	int wind_speed;
	
	while(loop){
		int reply = 0;
		printf("Enter a wind speed: ");
		scanf("%d", &wind_speed);
		getchar();


		if (wind_speed < 0){
			printf("Wind speed cannot be negative.\n");
			continue;
		}
		else if (wind_speed < 1)
			printf("Calm.\n");
		else if (wind_speed < 4)
			printf("Light air.\n");
		else if (wind_speed < 28)
			printf("Breeze.\n");
		else if (wind_speed < 48)
			printf("Gale.\n");
		else if (wind_speed < 64)
			printf("Storm.\n");
		else
			printf("Hurricane.\n");

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
