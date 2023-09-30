#include <stdio.h>


int main(void) {
	enum {NUL, SOH, STX, ETX};
	enum {VT = 11, FF, CR};
	enum {SO = 14, SI, DLE, CAN = 24, EM};
	enum {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC};

	printf("MY answer: \n");
	printf("0, 1, 2, 3\n");
	printf("11, 12, 13\n");
	printf("14, 15, 16, 24, 25\n");
	printf("45, 46, 47, 37, 38, 39\n\n");

	printf("Answer: \n");
	printf("%d, %d, %d, %d\n", NUL, SOH, STX, ETX);
	printf("%d, %d, %d\n", VT, FF, CR);
	printf("%d, %d, %d, %d, %d\n", SO, SI, DLE, CAN, EM);
	printf("%d, %d, %d, %d, %d, %d\n", ENQ, ACK, BEL, LF, ETB, ESC);
	
	 return 0;
}
