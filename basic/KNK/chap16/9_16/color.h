#ifndef COLOR_H
#define COLOR_H
#include <stdbool.h>

typedef struct {
	int red;
	int green;
	int blue;
} color;

color make_color(int red, int green, int blue);

int get_red(color c);
int get_green(color c);
int get_blue(color c);

bool equal_color(color c1, color c2);

color brighter(color c);
color darker(color c);

#endif


