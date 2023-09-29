#include <stdio.h>
#define RECTANGLE 0
#define CIRCLE 1

enum shape {RECTANGLE, CIRCLE};
typedef struct { int x, y;} point;

typedef struct {
	shape shape_kind;
	point center;
	union {
		struct {
			int height, width;
		} rectangle;
		struct {
			int radius;
		} circle;
	} u;
} rec_or_cir;

int main(void) {
	rec_or_cir.shape_kind = RECTANGLE;
	rec_or_cir.center.x = 10;
	rec_or_cir.rectangle.height = 25;
	rec_or_cir.rectangle.width = 8;

	return 0;
}
