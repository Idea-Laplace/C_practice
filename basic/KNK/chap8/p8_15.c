#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE (int) (sizeof(cipher) / sizeof(cipher[0]))
#define ENCODE_LOWER (cipher[j] - 'a' + shift) % 26 + 'a'
#define ENCODE_UPPER (cipher[j] - 'A' + shift) % 26 + 'A'


int main (void) {
	bool loop = true;

	while (loop) {
		char cipher[80], ch;
		int i, shift;

		// Input***************************************************

		printf("Enter message to be encrypted: ");
		for (i = 0; (ch = getchar()) != '\n'; ++i) {
			if (i >= SIZE)
				continue;
			cipher[i] = ch;
		}

		printf("Enter shift amount (1 - 25): ");
		scanf("%d", &shift);
		getchar();             // Littering '\n'
		//*********************************************************

		// Encrypting
		if (i > SIZE)
			printf("Warning: Entered message is more of %d characters.\n", SIZE);
		printf("Encrypted message: ");
		for (int j = 0; j < (i > SIZE ? SIZE : i); ++j)
			if (cipher[j] >= 'a' && cipher[j] <= 'z')
				putchar(ENCODE_LOWER);
			else if (cipher[j] >= 'A' && cipher[j] <= 'Z')
				putchar(ENCODE_UPPER);
			else
				putchar(cipher[j]);
		printf("\n");
		// ********************************************************

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
