#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int main (void) {
	bool loop = true;

	while (loop) {
		char ch;
		int vowel = 0;


		printf("Enter a sentence: ");
		while ((ch = getchar()) != '\n') {
			switch (toupper(ch)) {
				case 'A': case 'E': case 'I': case 'O': case 'U':
					++vowel;
					break;
				default : break;
			}
		}

		printf("Your sentence contains %d vowel(s).\n", vowel);


		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = getchar();
			getchar();

			switch (reply) {
				case 'y': printf("\n=========================\n"); break;
				case 'n': printf("Program terminated.\n"); loop = false; break;
				default : printf("Type y or n.\n"); break;
			}
		} while (reply != 'y' && reply != 'n');
	}
	system("pause");
	return 0;
}
