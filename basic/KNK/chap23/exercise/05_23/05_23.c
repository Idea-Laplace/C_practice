#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 30

long hex2long(char *);

int main(void) {
	char hex_repr[LEN + 1];

	printf("Enter a hexadecimal number: ");
	scanf("%30s", hex_repr);

	if (hex2long(hex_repr) == -1)
		printf("Invalid hexadecimal representation.\n");
	else
		printf("In decimal: %ld\n", hex2long(hex_repr));

	return 0;
}

long hex2long(char *hex_repr) {
	char *p = hex_repr;
	while (*p) {
		if (!isxdigit(*p++))
			return -1L;
	}
	// strtol: 'string to long', 16 is raix or base, 2nd argument
	//		   is a pointer, value to which it points would be modified
	//         if the pointer is other than NULL.
	//         A standard library function in <stdlib.h>
	return strtol(hex_repr, NULL, 16);
}

