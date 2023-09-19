// Modify square3.c so that the for loop initialize i, test i and increments i
// in particular, don't use any multiplication operator.
// square3.c, in section 6.3 of KNK
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int n, square = 0;
		printf("This program prints a table of squares.\n");
		printf("Enter number of entries in table: ");
		scanf("%d", &n);
		getchar();
		for (int i = 1; i <= n; ++i){
			square += i + i - 1;
			printf("%10d%10d\n", i, square);
		}
		
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
