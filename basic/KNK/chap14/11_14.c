#include <stdio.h>

#define ERROR(fstr, index)	\
fprintf(stderr, fstr, index)


int main(void) {
	ERROR("Range error: index = %d\n", __LINE__);
	return 0;
}
