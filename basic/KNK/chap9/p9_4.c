#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define ALPHABET 26


void read_word(int counts[ALPHABET]);
bool equal_array(int counts1[ALPHABET], int counts2[ALPHABET]);

int main (void) {
	bool loop = true;

	while (loop) {
		int count1[ALPHABET] = {0}, count2[ALPHABET] = {0};

		read_word(count1);
		read_word(count2);
		if (equal_array(count1, count2))
			printf("Two words are anagram.\n");
		else
			printf("Two words are not anagram.\n");


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


void read_word(int counts[ALPHABET]) {
	char ch;

	printf("Enter a word (letters only): ");
	while ((ch = getchar()) != '\n') {
		ch = toupper(ch);
		if (ch < 'A' || ch > 'Z')
			continue;
		counts[ch - 'A']++;
	}
}

bool equal_array(int counts1[ALPHABET], int counts2[ALPHABET]) {
	for (int i = 0; i < ALPHABET; ++i)
		if (counts1[i] != counts2[i])
			return false;
	return true;
}
