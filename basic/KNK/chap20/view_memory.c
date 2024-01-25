// Allow the user to view regions of computer memory.

#include <ctype.h>
#include <stdio.h>
#include <endian.h>

#define FLUSH while (getchar() != '\n')
typedef unsigned char BYTE;

int main (void) {
	unsigned long long addr;
	int i, n;
	BYTE *ptr;

	if (BYTE_ORDER == LITTLE_ENDIAN)
		printf("Byte representation: Little Endian.\n");
	else
		printf("Byte representation: BIG Endian.\n");
	

	// We can handle values of pointers as integer in particular way.
	printf("Address of main function: %#llx\n", (unsigned long long) main);
	printf("Address of addr variable: %#llx\n", (unsigned long long) &addr);

	printf("\nEnter a hexadecimal address: ");
	scanf("%llx", &addr);
	FLUSH;
	
	printf("Enter number of bytes to view: ");
	scanf("%d", &n);
	FLUSH;

	printf("\n");
	printf("Line      Address                Bytes                Characters\n");
	printf("----    ------------   -----------------------------  ----------\n");

	// We can put a type conversion on addr from unsigned long long to pointer
	// and vice versa
	ptr = (BYTE *) addr;

	// 10 bytes per a line, so the step increases by 10.
	for (int line = 0; n > 0; n -= 10, ptr += 10) {
		printf("%4d    ", line++);
		printf("%8llX   ", (unsigned long long) ptr);
		for (i = 0; i < 10 && i < n; i++)
			printf("%.2X ", *(ptr + i));

		// For visual purpose
		for (; i < 10; i++)
			printf("   ");
		printf(" ");
		//-------------------

		for (i = 0; i < 10 && i < n; i++) {
			BYTE ch = *(ptr + i);
			if (!isprint(ch))
				ch = '.';
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}
