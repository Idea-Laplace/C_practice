#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int i, temp,  reply = 0;
		printf("Enter an integer to initialize i: ");
		scanf("%d", &temp);
		i = temp;
		getchar();
		
		printf("The loop body is printf(\"%%d\", i++);\n");

		printf("(a) while (i < 10)...\n");
		while (i < 10)
			printf("%d", i++);
		printf("\n");
		i = temp;

		printf("(b) for (; i < 10;)...\n");
		for (; i < 10;)
			printf("%d", i++);
		printf("\n");
		i = temp;

		printf("(c) do{ } while (i < 10)...\n");
		do {
			printf("%d", i++);
		} while (i < 10);
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
