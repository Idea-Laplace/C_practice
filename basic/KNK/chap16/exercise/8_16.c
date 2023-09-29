#include <stdio.h>


typedef struct {
	int red;
	int green;
	int blue;
} color;

int main(void) {
	const color magneta = {255, 0, 255};
	printf("Magneta RGB info: \n");
	printf("Red  : %d\nGreen: %d\nBlue : %d\n", magneta.red, magneta.green, magneta.blue); 

	const color designated_magneta = {.red = 255, .blue = 255};
	printf("Magneta(designated ver.) RGB info: \n");
	printf("Red  : %d\nGreen: %d\nBlue : %d\n", designated_magneta.red,\
			designated_magneta.green, designated_magneta.blue); 

	
	return 0;
}
