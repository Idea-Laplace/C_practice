#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int tens, units;
    printf("Enter a 2-digit number: ");
    scanf("%d", &tens);

    units = tens % 10;
    tens = tens / 10;

    printf("The reversal is: %d%d\n", units, tens);

    system("pause");
    return 0;
}
