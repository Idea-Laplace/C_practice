#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i = 5, j = 3, k = 9;
    printf("%d %d\n", i/j, i%j);

    i = 2;
    j = 3;

    printf("%d\n", (i+10)%j);
    printf("%d\n", (i+10)%k/j);

    i = 1;
    j = 2;
    k = 3;

    printf("%d\n", (i+5)%(j+2)/k);

    system("pause");
    return 0;
}
