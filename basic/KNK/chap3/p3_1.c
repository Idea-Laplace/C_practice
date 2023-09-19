#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int month, date, year;

    printf("Enter a date (mm/dd/yyyy) > ");
    scanf("%2d /%2d /%4d", &month, &date, &year);
    printf("You entered the date: %.2d%.2d%d\n", year, month, date);

    system("pause");
    return 0;
}
