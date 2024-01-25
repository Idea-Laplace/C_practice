/*
   In computer graphics, colors are often stored as 3 numbers. representing red, green
   and blue intensities. Supposet that each number requires eight bits, and we'd like to
   store all three values in a single long integer. Write a macro named MK_COLOR with
   three parameters. MK_COLOR should return a long in which the last three bytes contain
   the red, green and blue intensities, with the red value as the last and the green value
   as the next to last byte.
*/

/* 
   Write macros named GET_RED, GET_GREEN, GET_BLUE that, when given a color as an
   argument, returns its 8-bit red, green, and blue intensities.
*/

#include <stdio.h>

#define BYTE 8
#define MK_COLOR(red, green, blue) ((long) (red) | ((green) << BYTE) | ((blue) << 2 * BYTE))
#define GET_RED(mk_color) ((Byte)((mk_color) & (1 << BYTE) - 1))
#define GET_GREEN(mk_color) ((Byte)((mk_color >> BYTE) & (1 << BYTE) - 1))
#define GET_BLUE(mk_color) ((Byte)((mk_color >> 2 * BYTE) & (1 << BYTE) - 1))

typedef unsigned char Byte;


int main(void) {
	Byte red, green, blue;
	long mk_color;

	printf("Enter an intensity of color red in hex: ");
	scanf("%hhx", &red);
	printf("Enter an intensity of color green in hex: ");
	scanf("%hhx", &green);
	printf("Enter an intensity of color blue in hex: ");
	scanf("%hhx", &blue);

	printf("\nRed: %#.2x,  Green: %#.2x,  Blue: %#.2x\n", red, green, blue);
	mk_color = MK_COLOR(red, green, blue);

	printf("In a single long byte form %#lx\n", mk_color);

	printf("Restore red: %#.2x\n", GET_RED(mk_color));
	printf("Restore green: %#.2x\n", GET_GREEN(mk_color));
	printf("Restore blue: %#.2x\n", GET_BLUE(mk_color));


	return 0;
}


