#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main(int argc, char **argv) {
	int code;
	FILE *fp;
	if (argc == 1)
		fp = stdin;
	else if (argc == 2) {
		fp = fopen(argv[1], "r");
		if (fp == NULL) {
			fprintf(stderr, "File %s cannot be opened\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		open(fp);
	}
	else {
		fprintf(stderr, "Too many arguments.\n");
		exit(EXIT_FAILURE);
	}
	fp = stdin;

	printf("i: insert, e: erase_all, p: print, s: save, o: open, q: quit\n");

	for (;;) {
		printf("Enter process code you want: ");
		code = getchar();
		while (getchar() != '\n');

		switch (code) {
			case 'i':
				insert(fp);
				break;
			case 'e':
				erase_all();
				break;
			case 'p':
				print();
				break;
			case 's':
				save();
				break;
			case 'o':
				open(NULL);
				break;
			case 'q':
				printf("Process terminated.\n");
				return 0;
			default:
				printf("Invalid code.\n");
				break;
		}
	}
}

