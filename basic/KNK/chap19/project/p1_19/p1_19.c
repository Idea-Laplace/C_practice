#include <stdio.h>
#include <stdbool.h>
#include "stackADT.h"

#define FLUSH while (getchar() != '\n')

int main(void) {
	bool loop = true;
	int symbol;
	int succeed;

	while (loop) {
		printf("Enter parentheses and/or braces: ");
		for (;;) {
			succeed = scanf("%[(){}\[\]]", &symbol);
			if (!succeed) {
				FLUSH;
				break;

		

