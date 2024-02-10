#include <stdio.h>
#include "stackADT2.h"

int main(void) {
	Stack s1, s2;

	s1 = create(5);
	s2 = create(10);

	for (int i = 0; i < 6; i++) {
		push(s1, i);
		push(s2, i);
	}

	destroy(s1);
	destroy(s2);

	return 0;
}

