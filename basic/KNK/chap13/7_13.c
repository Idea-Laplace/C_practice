#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char str[] = "Hello, world!";
	printf("%s\n", str);

	*str = 0;
	printf("%s\n", str);
	*str = 'H';

	str[0] = '\0';
	printf("%s\n", str);
	*str = 'H';

	strcpy(str, "");
	printf("%s\n", str);
	*str = 'H';

	strcat(str, "");
	printf("%s\n", str);
	system("pause");
	return 0;
}
