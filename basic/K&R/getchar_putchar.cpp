#include <stdio.h>
#include <stdlib.h>

int main(){
    int c;
    c = EOF;
    printf("%d\n",c);
    printf("%d\n", (c != EOF)==1);
    printf("%d\n", (c != EOF)==0);

    while((c = getchar()) != EOF)
        putchar(c);
    system("pause");
    return 0;
}