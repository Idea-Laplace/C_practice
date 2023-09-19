#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int reply = 0;
		int num;
		printf("Negative integer will cause an wrong result.\n");
		printf("Enter an integer to reverse: ");
		scanf("%d", &num);
		getchar();
		printf("The reversal is: ");
		do{
			printf("%d", num % 10);
			num = num / 10;
		} while (num > 0); //num itself would also be sufficient, but for clearity.
		printf("\n");

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
