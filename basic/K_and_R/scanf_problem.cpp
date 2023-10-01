#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
    char a;
    char b;
    printf("Insert two characters. > ");
    scanf("%c", &a);
    scanf("%c", &b);
    printf("a = %c, b = %c", a, b);
    
    system("pause");
    return 0;
}
