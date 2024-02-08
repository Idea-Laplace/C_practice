#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {
	FILE *fp;
	int input;
	int hour, minute;
	int r_hour, r_minute;
	char am_pm[5];
	printf("Enter a 24-hour time(hh:mm): ");
	scanf("%d :%d", &hour, &minute);

	if (argc != 2) {
		fprintf(stderr, "Usage: $p13_22 {file.dat}\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "File %s can't be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((input = fscanf(fp, "%2d :%2d", &r_hour, &r_minute)) != EOF) {
		if (r_hour < hour) {
			while (fgetc(fp) != '\n');
			continue;
		} else if (r_hour == hour && r_minute < minute) {
			while (fgetc(fp) != '\n');
			continue;
		} else {
			r_hour % 12 < r_hour ? strcpy(am_pm, "p.m.") : strcpy(am_pm, "a.m.");
			printf("Closest departure time is %.2d:%.2d %s, ", r_hour == 12 ? 12 : r_hour % 12, r_minute, am_pm);
			fscanf(fp, "%2d :%2d", &r_hour, &r_minute);
			printf("arrving at %.2d:%.2d %s.\n", r_hour == 12 ? 12 : r_hour % 12, r_minute, am_pm);
			break;
		}
	}

	if (input == EOF) {
		rewind(fp);
		fscanf(fp, "%2d :%2d", &r_hour, &r_minute);
		r_hour % 12 < r_hour ? strcpy(am_pm, "p.m.") : strcpy(am_pm, "a.m.");
		printf("Closest departure time is tomorrow %.2d:%.2d %s, ", r_hour == 12 ? 12 : r_hour % 12, r_minute, am_pm);
		fscanf(fp, "%2d :%2d", &r_hour, &r_minute);
		printf("arrving at tomorrow %.2d:%.2d %s.\n", r_hour == 12 ? 12 : r_hour % 12, r_minute, am_pm);
	}

	fclose(fp);
	return 0;
}



