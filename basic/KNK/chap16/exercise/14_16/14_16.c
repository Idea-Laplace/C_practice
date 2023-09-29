#include <stdio.h>
#include "shape.h"


int main(void) {
	point center1 = {2, 3};
	point center2 = {0, 0};
	point move = {1, 1};
	double scale = 1.5;
	figure fig1 = {MY_RECTANGLE, center1};
	fig1.object.rectangle.width = 5;
	fig1.object.rectangle.height = 7;

	figure fig2 = {MY_CIRCLE, center2};
	fig2.object.circle.radius = 1;

	printf("Fig 1 info: \n");
	printf("Shape: %s\n", fig1.kind == MY_CIRCLE ? "circle" : "rectangle");
	printf("Center: (%d, %d)\n", fig1.center.x, fig1.center.y);
	printf("Width: %d\t""HEIGHT: %d\n",\
		fig1.object.rectangle.width, fig1.object.rectangle.height);

	putchar('\n');

	printf("Fig 2 info: \n");
	printf("Shape: %s\n", fig2.kind == MY_CIRCLE ? "circle" : "rectangle");
	printf("Center: (%d, %d)\n", fig2.center.x, fig2.center.y);
	printf("Radius: %d\n", fig2.object.circle.radius);

	putchar('\n');

	if (compare_area(fig1, fig2))
		printf("Fig1 is %s than Fig2\n", compare_area(fig1, fig2) > 0 ? "larger" : "smaller");
	else
		printf("They have same area.\n");

	putchar('\n');

	fig1 = transition(fig1, move);
	printf("Fig 1 info(After transition): \n");
	printf("Shape: %s\n", fig1.kind == MY_CIRCLE ? "circle" : "rectangle");
	printf("Center: (%d, %d)\n", fig1.center.x, fig1.center.y);
	printf("Width: %d\t""HEIGHT: %d\n",\
		fig1.object.rectangle.width, fig1.object.rectangle.height);

	putchar('\n');

	fig1 = scale_figure(fig1, scale);
	printf("Fig 1 info(After scaled): \n");
	printf("Shape: %s\n", fig1.kind == MY_CIRCLE ? "circle" : "rectangle");
	printf("Center: (%d, %d)\n", fig1.center.x, fig1.center.y);
	printf("Width: %d\t""HEIGHT: %d\n",\
		fig1.object.rectangle.width, fig1.object.rectangle.height);
	return 0;
}
