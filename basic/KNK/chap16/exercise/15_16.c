#include <stdio.h>


int main(void) {
	enum weekdays {SUN, MON, TUE, WED, THR, FRI, SAT};
	typedef enum {SUN, MON, TUE, WED, THR, FRI, SAT} weekdays;

	return 0;
}
