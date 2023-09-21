#ifndef SPILT_TIME_H
#define SPILT_TIME_H

#define HOUR_FACTOR 3600
#define MIN_FACTOR 60

typedef struct {
	int hour;
	int min;
	int sec;
} time;

time split_time(int total_seconds);

#endif

