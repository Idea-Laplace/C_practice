#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE (int) (sizeof(anagram_check) / sizeof(anagram_check[0]))


int main (void) {
	bool loop = true;

	while (loop) {
		int anagram_check[26] = {0};
		int index;
		char ch;

		printf("Enter 1st word (letters only): ");
		while ((ch = getchar()) != '\n') {
			ch = toupper(ch);
			if (ch < 'A' || ch > 'Z') {
				printf("Enter letters only.\n");
				continue;
			}
			anagram_check[ch - 'A']++;
		}

		printf("Enter 2nd word (letters only): ");
		while ((ch = getchar()) != '\n') {
			ch = toupper(ch);
			if (ch < 'A' || ch > 'Z') {
				printf("Enter letters only.\n");
				continue;
			}
			anagram_check[ch - 'A']--;
		}

		for (index = 0; index < SIZE; ++index)
			if (anagram_check[index]) {
				printf("The words are not anagrams.\n");
				break;
			}
		if (index == SIZE)
			printf("The words are anagrams.\n");

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
