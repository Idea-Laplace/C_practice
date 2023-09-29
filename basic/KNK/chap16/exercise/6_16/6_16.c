#include "6_16.h"

time split_time(int total_seconds) {
	time conversion;

	conversion.hour = total_seconds / HOUR_FACTOR;
	total_seconds %= HOUR_FACTOR;
	
	conversion.min = total_seconds / MIN_FACTOR;
	total_seconds %= MIN_FACTOR;

	conversion.sec = total_seconds;

	return conversion;
}

