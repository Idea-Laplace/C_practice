#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9


int main(int argc, char *argv[]){
	char *planets[NUM_PLANETS] = {"Mercury", "Venus", "Earth", "Mars",\
								"Jupyter", "Saturn", "Uranus", "Neptune", "Pluto"};
	for (int i = 0; i < argc; ++i) {
		int j;
		for (j = 0; j < NUM_PLANETS; ++j) {
			int k;
			for (k = 0; k < strlen(planets[j]); ++k) {
				if (toupper(argv[i][k]) != toupper(planets[j][k]))
						break;
			}
			if (!argv[i][k]) {
					printf("%s is planet %d.\n", argv[i], j + 1);
					break;
			}
		}
		if (j == NUM_PLANETS)
			printf("%s is not planet.\n", argv[i]);
	}
	return 0;
}



