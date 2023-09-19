/***********************************************************
 * The prototypical Internet newbie is a fellow named B1FF,*
 * who has a unique way of writing messages.               *
 * Here's a typical B1FF communiques:                      *
 *                                                         *
 * H3y DUD3, C I5 R1LLY C00L!!!!!!!!!!                     *
 * *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define BUFFER 100
#define SIZE (int) (sizeof(message) / sizeof(message[0]))

int main (void) {
	bool loop = true;

	while (loop) {
		char message[BUFFER], ch;
		int index = 0, count = 0 ;
		printf("Enter message: ");
		while ((ch = getchar()) != '\n') {
			if (index >= BUFFER) {
				printf("Storage short has risen, try other messages within %d characters.\n", BUFFER);
				continue;
			}

			if (ch - 'a' >= 0 && ch - 'a' < 26)
				message[index++] = toupper(ch);
			else
				message[index++] = ch;
			++count;
		}

		printf("In B1FF-speak: ");
		for (int i = 0; i < count; ++i) {
			switch (message[i]) {
				case 'A': printf("4"); break;
				case 'B': printf("8"); break;
				case 'E': printf("3"); break;
				case 'I': printf("1"); break;
				case 'O': printf("0"); break;
				case 'S': printf("5"); break;
				default : printf("%c", message[i]); break;
			}
		}
		printf("!!!!!!!!!!\n");

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
