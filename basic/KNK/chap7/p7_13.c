#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main (void) {
	bool loop = true;

	while (loop) {
		int length = 0, count = 0, total = 0;
		char ch, identifier = ' ';
		bool subloop = true;

		printf("Enter a sentence: ");

		while (subloop) {
			switch (ch = getchar()) {
				case ' ': case '\t':
					total += length;
					length = 0;
					if (identifier != ' ' && identifier != '\t') {
						++count;
						identifier = ch;
						continue;
					}
					identifier = ch;
					break;
				case '\n':
					total += length;
					if (identifier != ' ' && identifier != '\t') {
						++count;
					}
					subloop = false;
					break;
				default :
					++length;
					identifier = ch;
					break;
			}
		}
		printf("Average word length %.1f\n", count == 0 ? 0 : (float) total / count);



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
