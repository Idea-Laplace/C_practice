#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
    char a;
    printf("Input two characters. > ");
    a = getchar();
    getchar();
    char b;
    scanf_s("%c", &b, sizeof(b));
    printf("a = %c, b = %c\n", a, b);
    
    system("pause");
    return 0;
}