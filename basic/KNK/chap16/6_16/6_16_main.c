#include <stdio.h>
#include "6_16.h"

int main(void) {
	time test;
	int total_seconds;

	printf("Enter total seconds to convert: ");
	scanf("%d", &total_seconds);

	test = split_time(total_seconds);

	printf("%02dh %02dm %02ds\n", test.hour, test.min, test.sec);
	return 0;
}
