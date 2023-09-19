#include <stdio.h>
//#define ENGLISH
#define FRENCH
//#define SPANISH

int main(void) {
#if defined(ENGLISH)
	puts("Insert Disk 1");
#elif defined(FRENCH) 
	puts("Inserez Le Disque 1");
#elif defined(SPANISH) 
	puts("Inserte El Disco 1");
#else
	puts("Language not specified.");
#endif
	return 0;
}

