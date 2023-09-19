#include <stdio.h>
#include <stdlib.h>

int main(){
    int nc;

    for(nc = 0; getchar() != EOF; nc++)
        ;
    printf("Number of characters: %4d\n", nc);
    system("pause");
    return 0;
}

