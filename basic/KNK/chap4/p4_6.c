#include <stdio.h>
#include <stdlib.h>

// This program show the check digit of a EAN, which is an abbreviation of
// European Article Number

int main(void)
{
    int ean[12], i;
    int first_sum = 0, second_sum = 0, total;
    printf("Enter the first 12 digits of a EAN: ");
    for (i = 0; i < 12; ++i)
    {
        scanf("%1d", &ean[i]);
        if (i % 2 == 0)
            second_sum += ean[i];
        else
            first_sum += ean[i];
    }

    total = 3 * first_sum + second_sum - 1;
    printf("Check digit: %d\n", 9 - total % 10);

    system("pause");
    return 0;
}
