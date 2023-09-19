#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int hundreds, tens, units;
    printf("Enter a 3-digit number: ");
    scanf("%1d%1d%1d", &hundreds, &tens, &units);

    printf("The reversal is: %d%d%d\n", units, tens, hundreds);

    system("pause");
    return 0;
}
