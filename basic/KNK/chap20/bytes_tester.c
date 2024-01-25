#include <stdio.h>
#include <stdlib.h>
#include "show_bytes.h"

#define FLUSH while (getchar() != '\n')

int main(void) {
	int reply;
	union {
		int i;
		float f;
		double d;
		void *p;
	} selection;

	selection.p = malloc(1);

	if (selection.p == NULL) {
		printf("Error in malloc(): could not allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	
	show_output_mode();
	for (;;) {
		printf("Type a process you want(i/f/d/p/q): ");
		reply = getchar();
		FLUSH;

		switch(reply) {
			case 'i':
				printf("Enter an integer: ");
				scanf("%d", &selection.i);
				FLUSH;
				show_int(selection.i);
				break;
			case 'f':
				printf("Enter a real number(float): ");
				scanf("%f", &selection.f);
				FLUSH;
				show_float(selection.f);
				break;
			case 'd':
				printf("Enter a real number(double): ");
				scanf("%lf", &selection.d);
				FLUSH;
				show_double(selection.d);
				break;
			case 'p':
				printf("Bytes representation for selection.p:\n");
				show_pointer(selection.p);
				break;
			case 'q':
				printf("Process terminated.\n");
				return 0;
			default :
				printf("Invalid input, ignored.\n");
				break;
		}
	}
}

