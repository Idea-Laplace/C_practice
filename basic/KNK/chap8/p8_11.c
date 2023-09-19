/*********************
 * Telephone mapping *
 * 2 = ABC  6 = MNO  *
 * 3 = DEF  7 = PRS  *
 * 4 = GHI  8 = TUV  *
 * 5 = JKL  9 = WXYZ *
 * *******************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE (int) (sizeof(phone_number) / sizeof(phone_number[0]))
#define MAX ((i > SIZE) ? SIZE : i)

int main (void) {
	bool loop = true;

	while (loop) {
		char input;
		char phone_number[15];
		int i;

		printf("The length of phone number should not\
 over 15 including separaters.\n\n");
		printf("Enter a phone number (in upper case): ");
		for (i = 0; (input = getchar()) != '\n'; ++i) {
			if (input >= 'a' && input <= 'z')
				input = toupper(input);
			if (i >= SIZE)
				continue;
			switch (input) {
				case 'A': case 'B': case 'C':
					phone_number[i] = '2'; break;
				case 'D': case 'E': case 'F':
					phone_number[i] = '3'; break;
				case 'G': case 'H': case 'I':
					phone_number[i] = '4'; break;
				case 'J': case 'K': case 'L':
					phone_number[i] = '5'; break;
				case 'M': case 'N': case 'O':
					phone_number[i] = '6'; break;
				case 'P': case 'R': case 'S':
					phone_number[i] = '7'; break;
				case 'T': case 'U': case 'V':
					phone_number[i] = '8'; break;
				case 'W': case 'X': case 'Y': case 'Z':
					phone_number[i] = '9'; break;
				default : phone_number[i] = input; break;
			}
		}
		
		if (i > SIZE)
			printf("Warning: The length of input should not over %d, including any characters.\n\n", SIZE);

		printf("In numeric form: ");
		for (int j = 0; j < MAX; ++j)
			printf("%c", phone_number[j]);
		printf("\n");
		
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
