#include <stdio.h>
#include <stdlib.h>  // system("pause")
#include <stdbool.h> // type true, false
#include <ctype.h>   // the function toupper()


int main(void){
	bool loop = true;
	while(loop){
		int num1, num2, temp;
		printf("This program is to calculate the gcd of 2 integers.\n");

		printf("Insert a number: ");
		scanf("%d", &num1);
		while(getchar() != '\n');

		printf("Insert another number: ");
		scanf("%d", &num2);
		while(getchar() != '\n');

		if(num1 * num2 == 0){
			printf("Both numbers must be nonzero integers.\n");
			continue;
		}

		while(num2 != 0){
			temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}
		printf("GCD: %d\n", num1 > 0 ? num1 : -num1);

		// Loop decision
		char reply;
		do{
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while(getchar() != '\n');

			switch(reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first character.\n"); break;
			}
		}while(reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}



