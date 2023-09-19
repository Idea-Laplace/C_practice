#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int number, count = 0;
		printf("Enter a number that confines range: ");
		scanf("%d", &number);
		printf("The even square(s) between 1 and n are(is):\n");
		getchar();
		for (int i = 2; i * i <= number; i += 2){
			printf("%d\n", i * i);
			++count;
		}
		printf("There are %d even square(s) between 1 and %d.\n", count, number);
		
		int reply = 0;
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
