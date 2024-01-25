/*
   rotate_left should return the result of shifting the bits in i
   to the left by n places, with the bits that were 'shifted off'
   move to the right end of i.
   rotate_right is similar, but it should 'rotate' bits to the right
   instead of the left.
*/

#include <stdio.h>

#define BYTE 8

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);


int main(void) {
	int reply;
	unsigned int i;
	int n;
	printf("Enter a hexadecimal number(up to 8 digits): ");
	scanf("%x", &i);
	while (getchar() != '\n');

	for (;;) {
		printf("What process do you want?(l/r/q): ");
		reply = getchar();
		while (getchar() != '\n');

		switch (reply) {
			case 'q': 
				printf("Process terminated.\n");
				return 0;
			case 'l':
				printf("How many shifts would you want to move: ");
				scanf("%d", &n);
				while (getchar() != '\n');
				printf("After %d left rotate: %#x\n", n, rotate_left(i, n));
				break;
			case 'r':
				printf("How many shifts would you want to move: ");
				scanf("%d", &n);
				while (getchar() != '\n');
				printf("After %d right rotate: %#x\n", n, rotate_right(i, n));
				break;
			default :
				printf("Invalid input, ignored.\n");
				break;
		}
	}
}

unsigned int rotate_right(unsigned int i, int n) {
	int rotate_shift = sizeof(unsigned int) * BYTE - n;
	unsigned int normal_bit = i >> n;
	unsigned int rotating_bit = (i & (1 << n) - 1) << rotate_shift;

	return normal_bit | rotating_bit;
}

unsigned int rotate_left(unsigned int i, int n) {
	int rotate_shift = sizeof(unsigned int) * BYTE - n;
	unsigned int normal_bit = i << n;
	unsigned int rotating_bit = (i & (~0 << rotate_shift)) >> rotate_shift;

	return normal_bit | rotating_bit;
}
