#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int i, reply;
	bool loop = true;

	while(loop){
		reply = 0;
		printf("Enter an integer: ");
		scanf("%d", &i);
		getchar();

		if (i < 0)
			printf("Input a nonnegative integer.\n", i);
		else if (i < 10)
			printf("The number %d has 1 digit.\n", i);
		else if (i < 100)
			printf("The number %d has 2 digit.\n", i);
		else if (i < 1000)
			printf("The number %d has 3 digit.\n", i);
		else if (i < 10000)
			printf("The number %d has 4 digit.\n", i);
		else
			printf("The number %d has more than 4 digit.\n", i);

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
