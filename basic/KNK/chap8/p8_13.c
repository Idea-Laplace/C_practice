#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE (int) (sizeof(last_name) / sizeof(last_name[0]))
#define BOUNDARY_CONDITION (i > SIZE ? SIZE : i)

int main (void) {
	bool loop = true;

	while (loop) {
		char last_name[20] = {0};
		char initial, letter;
		int i;

		printf("Enter a first and last name: ");
		initial = getchar();
		while (getchar() != ' '); // Empty body
		for (i = 0; (letter = getchar()) != '\n'; ++i) {
			if (i >= SIZE)
				continue;
			last_name[i] = letter;
		}

		if (i > SIZE)
			printf("Warning: The length of the given last name is larger than %d.\n\n", SIZE);
		
		printf("You entered the name: ");
		for (int j = 0; j < BOUNDARY_CONDITION; ++j)
			printf("%c", last_name[j]);
		printf(", %c.\n", initial);

		

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
