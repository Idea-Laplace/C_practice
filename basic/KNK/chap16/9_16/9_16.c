#include <stdio.h>
#include <stdbool.h>
#include "color.h"
#define FLUSH while (getchar() != '\n')

int main(void) {
	color clr1, clr2;
	int red, green, blue;
	int valid_input = false;

	for (;;) {
		printf("Enter first color(RGB)(num num num): ");
		valid_input = scanf("%d%d%d", &red, &green, &blue);
		FLUSH;

		if (valid_input != 3) {
			printf("Invalid input, process restarts.\n");
			continue;
		}

		clr1 = make_color(red, green, blue);

		printf("Enter second color(RGB)(num num num): ");
		valid_input = scanf("%d%d%d", &red, &green, &blue);
		FLUSH;

		if (valid_input != 3) {
			printf("Invalid input, process restarts.\n");
			continue;
		}

		clr2 = make_color(red, green, blue);

		break;
	}

	printf("They are %s color\n", equal_color(clr1, clr2) ? "same" : "different");
	printf("color1 is (%d, %d, %d).\n", get_red(clr1), get_green(clr1), get_blue(clr1));
	printf("Brighter version of color1: (%d, %d, %d)\n", brighter(clr1).red, brighter(clr1).green, brighter(clr1).blue);
	printf("Darker version of color1: (%d, %d, %d)\n", darker(clr1).red, darker(clr1).green, darker(clr1).blue);


	return 0;
}
