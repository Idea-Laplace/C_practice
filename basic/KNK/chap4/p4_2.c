#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int hundreds, tens, units;
    printf("Enter a 3-digit number: ");
    scanf("%d", &hundreds);

    units = hundreds % 10;
    tens = (hundreds / 10) % 10;
    hundreds = hundreds / 100;

    printf("The reversal is: %d%d%d\n", units, tens, hundreds);

    system("pause");
    return 0;
}
