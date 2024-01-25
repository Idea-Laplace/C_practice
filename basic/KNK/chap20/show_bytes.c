#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <endian.h>
#include <limits.h>
#include "show_bytes.h"

#define INTERNAL static

typedef unsigned char *unit_bytes;

// Mode ----------------------------------------------------------------
void show_output_mode(void) {
	if ((REVERSE && BYTE_ORDER == LITTLE_ENDIAN) || BYTE_ORDER == BIG_ENDIAN)
		printf("Endian: big endian\n");
	else
		printf("Endian: little endian\n");

	if (MODE == HEX)
		printf("Byte representation: Hexadecimal\n");
	else if (MODE == BIN)
		printf("Byte representation: Binary\n");
	else {
		printf("Error in marco value 'MODE', exit failure.\n");
		exit(EXIT_FAILURE);
	}
}
// ---------------------------------------------------------------------

INTERNAL void show_bytes(unit_bytes start, size_t length) {
	int i;

	//----------------------------------------------------------
	if (REVERSE) {
		if (MODE == HEX) {
			for (i = 1; i <= length; i++)
				printf(" %.2x", start[length - i]);
		}
		else if (MODE == BIN) {
			for (i = 1; i <= length; i++) {
				printf(" ");
				for (int k = 1; k <= CHAR_BIT; k++) 
					printf("%d", (start[length - i] >> CHAR_BIT - k) % BIN);
			}
		}
		printf("\n");
	}
	//----------------------------------------------------------
	else {
		if (MODE == HEX) {
			for (i = 0; i < length; i++)
				printf(" %.2x", start[i]);
		}
		else if (MODE == BIN) {
			for (i = 0; i < length; i++) {
				printf(" ");
				for (int k = 1; k <= CHAR_BIT; k++) 
					printf("%d", (start[i] >> CHAR_BIT - k) % BIN);
			}
		}
		printf("\n");
	}
	//----------------------------------------------------------
}

void show_int(int i) {
	show_bytes((unit_bytes) &i, sizeof i);
}

void show_float(float f) {
	show_bytes((unit_bytes) &f, sizeof f);
}

void show_double(double d) {
	show_bytes((unit_bytes) &d, sizeof d);
}

void show_pointer(void *p) {
	show_bytes((unit_bytes) &p, sizeof p);
}


