#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int i,  reply = 0;
		printf("The loop body is printf(\"%%d\", i);\n");

		printf("(a) for (i = 0; i < 10; ++i)...\n");
		for (i = 0; i < 10; ++i)
			printf("%d", i);
		printf("\n");

		printf("(b) for (i = 0; i < 10; i++)...\n");
		for (i = 0; i < 10; i++)
			printf("%d", i);
		printf("\n");

		printf("(c) for (i = 0; ++i < 10;)...\n");
		for (i = 0; ++i < 10; i)
			printf("%d", i);
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
