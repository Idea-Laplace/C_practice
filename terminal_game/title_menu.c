#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


static void quit(void) {
	return;
}

ENGINE title_menu(void) {
	bool loop = true;
	enum {START, SETTING, RANKING, ACHIVEMENT, QUIT} menu;
	const char *select[] = {"Start", "Setting", "Ranking", "Achivement", "Quit"};
	size_t len = 5;

	int max_width = 11;
	for (int i = 0; i < len; i++)
		if (max_width < strlen(*(select + i)))
			max_width = strlen(*(select + i));
	

	int location = START;
	int key = 0;

	do {
		key = getchar();
		while (key != '\n' && getchar() != '\n');
		system("clear");
		printf("                              CLI DUNGEON                              \n");
		printf("\n\n\n");

		switch (tolower(key)) {
			case 'w':
				location -= 1;
				if (location < 0)
					 location += len;
				break;
			case 's':
				location += 1;
				if (location >= len)
					 location -= len;
				break;
			case '\n':
				loop = false;
				break;
			default : break;
		}

		for (int i = 0; i < len; i++) {
			printf("                             %-*s ", max_width, select[i]);
			if (location == i) printf("<");
			putchar('\n');
		}
	} while (loop);
	system("clear");


	switch (location) {
		case START:
			return *quit;
		case SETTING:
			return *quit;
		case RANKING:
			return *quit;
		case ACHIVEMENT:
			return *quit;
		case QUIT:
			return *quit;
		default :
			printf("Error code -1: process terminated.\n");
			exit(EXIT_FAILURE);
	}
}

			



