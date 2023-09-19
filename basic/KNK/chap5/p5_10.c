#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int reply = 0;
		int grade;
		printf("Enter numerical grade: ");
		scanf("%d", &grade);
		getchar();
		printf("The letter grade is: ");

		switch(grade / 10){
			case 10:
				switch(grade % 10){
					case 0: printf("A\n"); break;
					default: printf("Error. Input a number in 0~100.\n"); break;
				}
				break;
			case 9: printf("A\n"); break;
			case 8: printf("B\n"); break;
			case 7: printf("C\n"); break;
			case 6: printf("D\n"); break;
			case 5:case 4:case 3:case 2:case 1: printf("F\n"); break;
			case 0:
				switch(grade >= 0){
					case 1: printf("F\n"); break;
					default: printf("Error. Input a number in 0~100.\n"); break;
				}
				break;
			default: printf("Input a number in 0~100.\n"); break;
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
