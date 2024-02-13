// a\: e0, e\:e8, e^:ea, e/:e9, i^:ee, o^:f4, u^:fb 
// Use the program with output redirection, such as vim
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	setlocale(LC_ALL, "en_US.ISO88591");

	printf("C\xf4te d'Azur\n");
	printf("cr\xe8me br\xfbl\xe9""e\n");
	printf("cr\xe8me fra\xee""che\n");
	printf("Fahrvergn\xfbgen\n");
	printf("t\xeate-\xe0-t\xeate\n");
	return 0;
}

