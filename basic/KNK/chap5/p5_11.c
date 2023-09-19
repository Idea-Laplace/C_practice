#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int reply = 0;
		int tens, units;
		printf("Enter a 2-digit number: ");
		scanf("%1d%1d", &tens, &units);
		getchar();
		printf("You entered the number ");

		switch(tens){
			case 1:
				switch(units){
					case 0: printf("ten.\n"); break;
					case 1: printf("eleven.\n"); break;
					case 2: printf("twelve.\n"); break;
					case 3: printf("thirteen.\n"); break;
					case 4: printf("fourteen.\n"); break;
					case 5: printf("fifteen.\n"); break;
					case 6: printf("sixteen.\n"); break;
					case 7: printf("seventeen.\n"); break;
					case 8: printf("eighteen.\n"); break;
					case 9: printf("nineteen.\n"); break;
				}
				break;
			case 2:
				printf("twenty");
				break;
			case 3:
				printf("thirty");
				break;
			case 4:
				printf("forty");
				break;
			case 5:
				printf("fifty");
				break;
			case 6:
				printf("sixty");
				break;
			case 7:
				printf("seventy");
				break;
			case 8:
				printf("eighty");
				break;
			case 9:
				printf("ninety");
				break;
			default: printf("Error.\n"); break;
		}

		if (tens != 1)
			switch(units){
				case 0: printf(".\n"); break;
				case 1: printf("-one.\n"); break;
				case 2: printf("-two.\n"); break;
				case 3: printf("-three.\n"); break;
				case 4: printf("-four.\n"); break;
				case 5: printf("-five.\n"); break;
				case 6: printf("six.\n"); break;
				case 7: printf("-seven.\n"); break;
				case 8: printf("-eight.\n"); break;
				case 9: printf("-nine.\n"); break;
				default: printf("Error.\n"); break;
			}

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
