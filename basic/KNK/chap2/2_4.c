#include <stdio.h>
#include <stdlib.h>
// Intentionally print uninitialized variables

int main(void)
{
    int a1, a2, a3, a4, a5;
    printf("%d , %d, %d, %d, %d", a1, a2, a3, a4, a5);

    system("pause");
    return 0;
}
