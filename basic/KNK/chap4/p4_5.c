#include <stdio.h>
#include <stdlib.h>
#define TOTAL_SUBTRACTION 1

int main(void)
{
    int upc[11], i;
    int first_sum = 0, second_sum = 0, total;
    printf("Enter the first 11 digits of a UPC: ");
    for (i = 0; i < 11; ++i)
    {
        scanf("%1d", &upc[i]);
        if (i % 2 == 0)
            first_sum += upc[i];
        else
            second_sum += upc[i];
    }

    total = 3 * first_sum + second_sum - TOTAL_SUBTRACTION;
    printf("Check digit: %d\n", 9 - total % 10);

    system("pause");
    return 0;
}
