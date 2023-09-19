#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void){
	int i, j, reply;
	_Bool loop = TRUE, subloop;

	while (loop){
		subloop = TRUE;
		
		printf("In this program, 1 means greater than, 0 means equal and -1 means smaller than.\n");
		printf("Enter 2 integers to compare with: ");
		scanf("%d%d", &i, &j);
		getchar();
		//printf("\n%d\n\n", i >= j ? i > j : -1); what I first thought.
		printf("\n%d\n\n", (i > j) - (i < j)); // Answer in KNK homepage

		while (subloop){
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply){
				case 'y': 
					printf("\n====================================================\n");
					subloop = FALSE;
					break;
				case 'n':
					printf("\nProgram terminated.\n");
					subloop = loop = FALSE;
					break;
				default :
					printf("Type y or n.\n");
					break;
			}
		}
	}
	system("pause");
	return 0;
}
