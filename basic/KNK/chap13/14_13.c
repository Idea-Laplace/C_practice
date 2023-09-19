#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
	char s[] = "Hsjodi", *p;
	for (p = s; *p; ++p)
		--*p;
	puts(s);
	system("pause");
	return 0;
}
