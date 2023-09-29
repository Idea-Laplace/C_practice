#include <stdio.h>
#include "shape.h"


int compare_area(figure fig1, figure fig2) {
	double area1, area2;

	if (fig1.kind == MY_RECTANGLE) 
		area1 = fig1.object.rectangle.width * fig1.object.rectangle.height;
	else
		area1 = PI * fig1.object.circle.radius * fig1.object.circle.radius;

	if (fig2.kind == MY_RECTANGLE) 
		area2 = fig2.object.rectangle.width * fig2.object.rectangle.height;
	else
		area2 = PI * fig2.object.circle.radius * fig2.object.circle.radius;


	if (area1 > area2)
		return 1;
	else if (area1 < area2)
		return -1;
	else
		return 0;
}


figure transition(figure fig, point move) {
	fig.center.x += move.x;
	fig.center.y += move.y;
	return fig;
}


figure scale_figure(figure fig, double scale) {
	if (fig.kind == MY_RECTANGLE) {
		fig.object.rectangle.width *= scale;
		fig.object.rectangle.height *= scale;
	}

	else
		fig.object.circle.radius *= scale;

	return fig;
}
