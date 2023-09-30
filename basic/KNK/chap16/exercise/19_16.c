#include <stdio.h>

int main(void) {
	typedef struct {
		char name[40 + 1];
		int year;
		enum {EM, SS} type;
		int players;
	} pinball_machine;

	return 0;
}
