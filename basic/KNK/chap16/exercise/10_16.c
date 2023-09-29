#include <stdio.h>
#include <stdbool.h>
#define FLUSH while(getchar() != '\n')


typedef struct {
	int x, y;
} point;

typedef struct {
	point upper_left;
	point lower_right;
} rectangle;

int area(rectangle r);
point center(rectangle r);
rectangle transition(int x, int y, rectangle r);
bool inner_point(point p, rectangle r);


int main(void) {
	int x1, x2, y1, y2;
	int trans_x, trans_y;
	int valid_input;
	rectangle r;
	for (;;) {
		printf("Enter a upper-left point(x, y): ");
		valid_input = scanf("%d ,%d", &x1, &y1);
		FLUSH;

		if (valid_input != 2) {
			printf("Invalid input, process restarts.\n");
			continue;
		}
		

		printf("Enter a lower-right point(x, y): ");
		valid_input = scanf("%d ,%d", &x2, &y2);
		FLUSH;

		if (valid_input != 2) {
			printf("Invalid input, process restarts.\n");
			continue;
		}

		if (x1 > x2 || y1 < y2) {
			printf("Not valid point value, remind the \'upper-left\' and \'lower-right\'.\n");
			continue;
		}
		break;
	}

	r.upper_left.x = x1;
	r.upper_left.y = y1;
	r.lower_right.x = x2;
	r.lower_right.y = y2;

	printf("Rectangle: {(x, y)| %d <= x <= %d, %d <= y <= %d}\n",\
								r.upper_left.x, r.lower_right.x, r.lower_right.y, r.upper_left.y);
	printf("Area: %d\n", area(r));
	printf("Center: (%d, %d)\n", center(r).x, center(r).y);

	for (;;) {
		printf("Enter transition vector in form of x, y: ");
		valid_input = scanf("%d ,%d", &trans_x, &trans_y);

		if (valid_input != 2) {
			printf("Invalid input, process restarts.\n");
			continue;
		}
		break;
	}

	r = transition(trans_x, trans_y, r);

	printf("Transition by (%d, %d): {(x, y)| %d <= x <= %d, %d <= y <= %d}\n", trans_x, trans_y, \
								r.upper_left.x, r.lower_right.x, r.lower_right.y, r.upper_left.y);
	

	for (;;) {
		printf("Enter an arbitay point in form of x, y: ");
		valid_input = scanf("%d ,%d", &trans_x, &trans_y);

		if (valid_input != 2) {
			printf("Invalid input, process restarts.\n");
			continue;
		}
		break;
	}

	printf("(%d, %d) is%sin the given rectangle.\n", trans_x, trans_y, inner_point((point) {trans_x, trans_y}, r) ? " ": " not ");
	return 0;
}


int area(rectangle r) {
	return (r.upper_left.y - r.lower_right.y) * (r.lower_right.x - r.upper_left.x);
}

point center(rectangle r) {
	return (point) {(r.upper_left.x + r.lower_right.x) / 2, (r.upper_left.y + r.lower_right.y) / 2};
}


rectangle transition(int x, int y, rectangle r) {
	r.upper_left.x += x;
	r.lower_right.x += x;
	r.upper_left.y += y;
	r.lower_right.y += y;

	return r;
}

bool inner_point(point p, rectangle r) {
	if (p.x < r.upper_left.x || p.x > r.lower_right.x)
		return false;
	if (p.y > r.upper_left.y || p.y < r.lower_right.y)
		return false;

	return true;
}







