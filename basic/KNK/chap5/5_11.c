#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int area_code, reply;
	bool loop = true;

	while (loop){
		reply = 1;

		printf("Given area codes: 229, 404, 470, 478, 678, 706, 762, 770, 912.\n");
		printf("Enter an area code (3 digit): ");
		scanf("%3d", &area_code);
		getchar();
		printf("\n");
		
		switch (area_code){
			case 229: printf("Albany\n"); break;
			case 404: printf("Atlanta\n"); break;
			case 470: printf("Atlanta\n"); break;
			case 478: printf("Macon\n"); break;
			case 678: printf("Atlanta\n"); break;
			case 706: printf("Columbus\n"); break;
			case 762: printf("Columbus\n"); break;
			case 770: printf("Atlanta\n"); break;
			case 912: printf("Savannah\n"); break;
			default: printf("Area code not recognized.\n"); break;
		}

		while (reply != 'y' && reply != 'n'){
			printf("\nLoop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply){
				case 'y': printf("\n"); break;
				case 'n': printf("\nProgram terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		}
	}
	system("pause");
	return 0;
}
