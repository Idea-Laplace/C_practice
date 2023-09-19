#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	bool loop = true;

	while(loop){
		int prime_testing, d;
		int reply = 0;
		printf("Enter a positive integer to test whether it is a prime: ");
		scanf("%d", &prime_testing);
		getchar();
		
		if (prime_testing == 1){
			printf("Enter a value larger than 1.\n");
			continue;
		}

		if (prime_testing == 2 || prime_testing == 3){
			printf("%d is a prime number.\n", prime_testing);
		}
		else{
			for (d = 2; d * d <= prime_testing; ++d){
				if (prime_testing % d == 0){
					printf("%d is divided by %d.\n", prime_testing, d);
					break;
				}
			}
			if (d * d > prime_testing) 
				printf("%d is a prime number.\n", prime_testing);
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
