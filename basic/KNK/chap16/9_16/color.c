#include <stdio.h>
#include <stdbool.h>
#include "color.h"

color make_color(int red, int green, int blue) {
	red = red > 0 ? red : 0;
	green = green > 0 ? green : 0;
	blue = blue > 0 ? blue : 0;

	red = red > 255 ? 255 : red;
	green = green > 255 ? 255 : green;
	blue = blue > 255 ? 255 : blue;

	return (color) {red, green, blue};
}

int get_red(color c) {
	return c.red;
}

int get_green(color c) {
	return c.green;
}

int get_blue(color c) {
	return c.blue;
}

bool equal_color(color c1, color c2) {
	if (c1.red != c2.red)
		return false;
	if (c1.green != c2.green)
		return false;
	if (c1.blue != c2.blue)
		return false;
	return true;
}

color brighter(color c) {
	if (!c.red && !c.green && !c.blue)
		return (color) {3, 3, 3};

	c.red = c.red > 0 && c.red < 3 ? 3 : c.red;
	c.green = c.green > 0 && c.green < 3 ? 3 : c.green;
	c.blue = c.blue > 0 && c.blue < 3 ? 3 : c.blue;
	c.red = (int) (c.red / 0.7);
	c.green = (int) (c.green / 0.7);
	c.blue = (int) (c.blue / 0.7);

	c.red = c.red > 255 ? 255 : c.red;
	c.green = c.green > 255 ? 255 : c.green;
	c.blue = c.blue > 255 ? 255 : c.blue;

	return (color) {c.red, c.green, c.blue};
}

color darker(color c) {
	c.red = (int) (c.red * 0.7);
	c.green = (int) (c.green * 0.7);
	c.blue = (int) (c.blue * 0.7);

	return (color) {c.red, c.green, c.blue};
}
