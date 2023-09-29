#ifndef SHAPE_H
#define SHAPE_H


// MACRO CONSTANTS
#define MY_RECTANGLE 1
#define MY_CIRCLE 2
#define PI 3.14159

// STRUCT=====================================
typedef struct {int x, y;} point;

typedef struct {
	int kind;
	point center;
	union {
		struct {
			int height, width;
		} rectangle;
		struct {
			int radius;
		} circle;
	} object;
} figure;
// ============================================

// Function(s)
int compare_area(figure, figure);
figure transition(figure fig, point move);
figure scale_figure(figure fig, double scale);

#endif
