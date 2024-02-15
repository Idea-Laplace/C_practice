/*
   In each of the following statements, assume that the variable i
   has the indicated original type. Using macors from the <inttypes.h>
   header, modify each statement so that it will work correctly if
   the type of i is changed to the indicated new type.

   
   (a) printf("%d", i); int -> int8_t
   (b) printf("%12.4d", i); int -> int32_t
   (c) printf("%-6o", i); unsigned int -> uint16_t
   (d) printf("%#x", i); unsigned int -> uint64_t
*/

#include <inttypes.h>  // These representations are in inttypes.h, not stdint.h
#include <stdio.h>

int main(void) {
	int i = 15;
	unsigned int j = 15;

	// Macros should be outside of strings.
	printf("%"PRId8"\n", (int8_t)i);
	printf("%12.4"PRId32"\n", (int32_t)i);
	printf("%-6"PRIo16"\n", (uint16_t)j);
	printf("%#"PRIx64"\n", (uint64_t)j);

	return 0;
}

