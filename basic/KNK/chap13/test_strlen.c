#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(arr) ((int) sizeof(arr) / sizeof(*arr))
#define TEST_WORD "foo"


int main(void){
	printf("foo\n");
	printf("The arr_length of \'foo\' is %d\n", LEN(TEST_WORD));
	printf("The strlen(\"foo\") is %d\n", strlen(TEST_WORD));
	printf("The strlen function does not count null charcater.\n");
	system("pause");
	return 0;
}

