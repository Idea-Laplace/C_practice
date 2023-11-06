#include "../inventory/inventory.h"

int compare_part(const void *p, const void *q) {
	return ((struct part *) q)->number - ((struct part *) p)->number;
}


